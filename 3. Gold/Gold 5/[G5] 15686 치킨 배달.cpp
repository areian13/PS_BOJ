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

struct Pos {
	int y, x;
};

vector<Pos> home, chicken;
vector<bool> isAvailable;
int result = INT_MAX;

int Dist(Pos a, Pos b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

void ChickenStreet(int idx, int cnt, int m)
{
	if (cnt == m)
	{
		int temp = 0;
		For(home.size())
		{
			int dist = INT_MAX;
			Forj(chicken.size())
			{
				if (isAvailable[j])
					dist = min(dist, Dist(home[i], chicken[j]));
			}
			temp += dist;
		}
		result = min(result, temp);
		return;
	}

	if (idx == chicken.size())
		return;

	isAvailable[idx] = true;
	ChickenStreet(idx + 1, cnt + 1, m);

	isAvailable[idx] = false;
	ChickenStreet(idx + 1, cnt, m);
}

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	For(n)
	{
		Forj(n)
		{
			int state;
			Cin state;

			if (state == 1)
				home.push_back({ i,j });
			elif(state == 2)
				chicken.push_back({ i,j });
		}
	}
	isAvailable.resize(chicken.size(), false);

	ChickenStreet(0, 0, m);
	Cout result;
}