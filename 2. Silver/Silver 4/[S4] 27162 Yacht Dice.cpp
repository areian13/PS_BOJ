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

int Value(array<int, 3>& dice, int idx)
{
	if (among(1, idx, 6))
	{
		int cnt = 0;
		For(3)
			cnt += (dice[i] == idx);
		return idx * (cnt + 2);
	}

	elif(idx == 7)
	{
		if (dice[0] == dice[1] && dice[1] == dice[2])
			return dice[0] * 4;
		elif(dice[0] == dice[1] && dice[1] != dice[2])
			return dice[1] * 4;
		elif(dice[0] != dice[1] && dice[1] == dice[2])
			return dice[1] * 4;
	}

	elif(idx == 8)
	{
		if (dice[0] == dice[1] && dice[1] == dice[2])
		{
			if (dice[0] == 6)
				return dice[0] * 3 + 5 * 2;
			else
				return dice[0] * 3 + 6 * 2;
		}
		elif(dice[0] != dice[1] && dice[1] == dice[2])
		{
			return max(dice[1] * 3 + dice[0] * 2, dice[1] * 2 + dice[0] * 3);
		}
		elif(dice[0] == dice[1] && dice[1] != dice[2])
			return max(dice[1] * 3 + dice[2] * 2, dice[1] * 2 + dice[2] * 3);
	}
	elif(idx == 9)
	{
		if (dice[0] != dice[1] && dice[1] != dice[2])
		{
			if (among(1, dice[0], 5) && among(1, dice[1], 5) && among(1, dice[2], 5))
				return 30;
		}
	}
	elif(idx == 10)
	{
		if (dice[0] != dice[1] && dice[1] != dice[2])
		{
			if (among(2, dice[0], 6) && among(2, dice[1], 6) && among(2, dice[2], 6))
				return 30;
		}
	}
	elif(idx == 11)
	{
		if (dice[0] == dice[1] && dice[1] == dice[2])
			return 50;
	}
	else
	{
		int sum = 0;
		For(3)
			sum += dice[i];
		return sum + 6 + 6;
	}
	return 0;
}
int main()
{
	FastIO;

	string availPed;
	Cin availPed;

	array<int, 3> dice;
	For(3)
		Cin dice[i];
	sort(stoe(dice));

	int result = 0;
	For(12)
		result = max(result, Value(dice, i + 1) * (availPed[i] == 'Y'));
	Cout result;
}