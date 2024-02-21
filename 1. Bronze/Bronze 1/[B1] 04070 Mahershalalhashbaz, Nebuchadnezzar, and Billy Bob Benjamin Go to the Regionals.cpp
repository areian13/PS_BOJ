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

bool IsValidTeam(int start, int k, vector<int>& nameSize)
{
	int sum = 0;
	For(k)
		sum += nameSize[start + i];
	if (nameSize[start] * k < sum - 2 * k || sum + 2 * k < nameSize[start] * k)
		return false;
	return true;
}

int main()
{
	FastIO;

	int tc = 0;
	while (true)
	{
		int n, k;
		Cin n >> k;
		if (!n && !k)
			break;

		vector<int> nameSize(n);
		For(n)
		{
			string name;
			Cin name;
			nameSize[i] = name.size();
		}
		sort(stoe(nameSize));

		string result = "yes";
		for (int i = 0; i < n; i += k)
		{
			if (!IsValidTeam(i, k, nameSize))
				result = "no";
		}
		printf("Case %d: %s\n\n", ++tc, result.c_str());
	}
}