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

	vector<bool> switchs(n + 1);
	Foro(n)
	{
		bool isOn;
		Cin isOn;
		switchs[i] = isOn;
	}

	int q;
	Cin q;

	while (q--)
	{
		int gender, num;
		Cin gender >> num;

		switch (gender)
		{
		case 1:
		{
			for (int i = num; i <= n; i += num)
				switchs[i] = !switchs[i];
			break;
		}
		case 2:
		{
			int size;
			for (size = 0; 1 <= num - size && num + size <= n; size++)
			{
				if (switchs[num - size] != switchs[num + size])
				{
					size--;
					break;
				}
				if (!(1 <= num - size - 1 && num + size + 1 <= n))
					break;
			}
			for (int i = num - size; i <= num + size; i++)
				switchs[i] = !switchs[i];
			break;
		}
		}
	}
	Foro(n)
	{
		Cout switchs[i] fspc;
		if (i % 20 == 0)
			Enter;
	}
}