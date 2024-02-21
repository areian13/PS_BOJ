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

	int n;
	Cin n;

	int dir = 1;
	int time = 1;
	For(n)
	{
		string s;
		int x;
		Cin s >> x;

		bool isRevTime = (s == "HOURGLASS");
		bool isSynchro = (time == x);
		bool isOverload = (isRevTime && isSynchro);

		string clap = "NO";
		if (isOverload)
			goto IS_OVERLOAD;
		if (isRevTime)
			dir *= -1;
		if (isSynchro)
			clap = "YES";

	IS_OVERLOAD:
		Cout time spc clap Endl;

		if (time == 12 && dir == 1)
			time = 0;
		elif(time == 1 && dir == -1)
			time = 13;

		time += dir;
	}
}