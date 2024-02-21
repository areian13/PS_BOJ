#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cfloat>
#include <cstring>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

double Avg(int start, int end, vector<int>& preSum)
{
	return (double)(preSum[end] - preSum[start - 1]) / (end - start + 1);
}

double Error(int start, int end, vector<vector<double>>& errorDP, vector<int>& preSum)
{
	if (errorDP[start][end] != -1.0)
		return errorDP[start][end];

	double avg = Avg(start, end, preSum);
	double result = 0;
	for (int i = start; i <= end; i++)
		result += pow(preSum[i] - preSum[i - 1] - avg, 2);
	return errorDP[start][end] = result;
}

double MinError(int k, double sum, int b, int n,
	vector<int>& preSum, vector<vector<double>>& dp, vector<vector<double>>& errorDP)
{
	if (k > n)
		return dp[n][b] = sum;

	if (dp[k][b] != -1.0)
		return dp[k][b];

	if (b == 1 || k == n)
	{
		double error = Error(k, n, errorDP, preSum);
		return dp[k][b] = sum + error;
	}

	double result = DBL_MAX;
	for (int i = k; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			double error = Error(i, j, errorDP, preSum);
			result = min(result, MinError(j + 1, sum + error, b - 1, n, preSum, dp, errorDP));
		}
	}
	return dp[k][b] = result;
}

int main()
{
	FastIO;

	int b, n;
	Cin b >> n;

	vector<int> preSum(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int f;
		Cin f;

		preSum[i] = preSum[i - 1] + f;
	}

	vector<vector<double>> dp(n + 1, vector<double>(b + 1, -1.0));
	vector<vector<double>> errorDP(n + 1, vector<double>(n + 1, -1.0));
	
	double result = MinError(1, 0.0, b, n, preSum, dp, errorDP);
	lf(4);
	Cout result Endl;
}