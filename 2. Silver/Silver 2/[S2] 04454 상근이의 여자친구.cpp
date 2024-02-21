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

double UsedOil(double a, double b, double c, double d, double v)
{
	return a * pow(v, 4) + b * pow(v, 3) + c * pow(v, 2) + d * v;
}

int main()
{
	FastIO;

	while (true)
	{
		double a, b, c, d, m, l;
		Cin a >> b >> c >> d >> m >> l;

		if (cin.eof())
			break; 

		double start = 0;
		double end = INT_MAX;
		double result;
		while (start <= end)
		{
			double mid = (start + end) / 2;
			double t = m / mid;

			double usedOil = UsedOil(a, b, c, d, mid) * t;
			//Cout start spc end spc usedOil spc mid Endl;

			if(abs(start - end) < 0.00001)
			{
				result = mid;
				break;
			}

			if (usedOil > l)
				end = mid;
			elif(usedOil < l)
				start = mid;
		
		}
		printf("%.2lf\n", result - 0.005);
	}
}