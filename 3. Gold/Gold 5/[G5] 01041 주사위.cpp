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

int main()
{
	FastIO;

	ULLONG n;
	Cin n;
	
	ULLONG nofFace = (n - 2) * (5 * n - 6);
	ULLONG nofEdge = 8 * n - 12;
	ULLONG nofVertex = 4;

	ULLONG a, b, c, d, e, f;
	Cin a >> b >> c >> d >> e >> f;

	if (n == 1)
	{
		Cout a + b + c + d + e + f - max({ a,b,c,d,e,f });
		return 0;
	}
	ULLONG face = min({ a,b,c,d,e,f });
	ULLONG edge = min({
		a + b,a + c,a + d,a + e,
		f + b,f + c,f + d,f + e,
		d + e,e + c,c + b,b + d
		});
	ULLONG vertex = min({
		a + b + c,a + c + e,a + e + d,a + d + b,
		f + b + c,f + c + e,f + e + d,f + d + b,
		});
	Cout nofFace * face + nofEdge * edge + nofVertex * vertex;
}