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

	int n, k;
	Cin n >> k;

	string str;
	For(n)
	{
		char c;
		Cin c;
		str += c;
	}
	
	string target = str;
	sort(stoe(target));

	unordered_map<string, bool> isVisited;
	isVisited[str] = true;

	queue<pair<string, int>> Q;
	Q.push({ str,0 });

	int result = -1;
	while (!Q.empty())
	{
		pair<string, int> cur = Q.front();
		Q.pop();

		if (cur.first == target)
		{
			result = cur.second;
			break;
		}
		For(n - k + 1)
		{
			string temp = cur.first;
			reverse(temp.begin() + i, temp.begin() + i + k);

			if (isVisited[temp])
				continue;

			isVisited[temp] = true;
			Q.push({ temp, cur.second + 1 });
		}
	}
	Cout result;
}