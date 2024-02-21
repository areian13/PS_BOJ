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
#include <random>

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

struct Pos
{
	int y, x;
};

double Dist(Pos a, Pos b)
{
	return sqrt(pow(a.y - b.y, 2) + pow(a.x - b.x, 2));
}

int main()
{
	FastIO;

	int tc;
	Cin tc;

	while (tc--)
	{
		int n;
		Cin n;

		vector<string> space(n);
		Pos start;
		For(n)
		{
			Cin space[i];
			Forj(n)
			{
				if (space[i][j] == 's')
					start = { i,j };
			}
		}

		double minDist = INT_MAX;
		Pos end;
		For(n)
		{
			Forj(n)
			{
				if (space[i][j] != 'p')
					continue;
		
				double dist = Dist(start, { i,j });
				if (dist < minDist)
				{
					minDist = dist;
					end = { i,j };
				}
			}
		}
		printf("(%d,%d):(%d,%d):%.2lf\n", start.y, start.x, end.y, end.x, minDist);
	}
}