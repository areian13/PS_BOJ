#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define	COUT cout << "OUT: " <<
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
#define ulf cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

int main()
{
	FastIO;

	int k;
	Cin k;

	vector<double> coef(k + 1);
	For(k + 1)
		Cin coef[i];

	double a, b, n;
	Cin a >> b >> n;

	double lValue = 0;
	For(k + 1)
		lValue += coef[i] / (k + 1 - i) * (pow(b, k + 1 - i) - pow(a, k + 1 - i));

	double result;
	{
		double dx = (b - a) / n;

		double start = 0;
		double end = dx;

		while (start <= end)
		{
			double eps = (start + end) / 2;

			double rValue = 0;
			For(k + 1)
			{
				double temp = 0;
				for (int j = 0; j < n; j++)
					temp += pow(a + j * dx + eps, k - i);
				rValue += temp * coef[i] * dx;
			}

			if (abs(lValue - rValue) <= 1e-4)
			{
				result = eps;
				break;
			}

			if (lValue < rValue)
				end = eps;
			elif(lValue > rValue)
				start = eps;
		}
	}
	lf(4);
	Cout result;
}