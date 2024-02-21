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

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

int main()
{
	FastIO;

	int tc;
	Cin tc;

	while (tc--)
	{
		int h, w;
		Cin h >> w;

		vector<vector<char>> map(h, vector<char>(w));
		For(h)
		{
			Forj(w)
				Cin map[i][j];
		}
		
		array<bool, 26> hasKey = { false, };
		string keys;
		Cin keys;

		if (keys != "0")
		{
			for (char key : keys)
				hasKey[key - 'a'] = true;
		}

		vector<Pos> starts;
		For(w)
		{
			if (map[0][i] != '*')
				starts.push_back({ 0,i });
			if (map[h - 1][i] != '*')
				starts.push_back({ h - 1,i });
		}
		for (int i = 1; i < h - 1; i++)
		{
			if (map[i][0] != '*')
				starts.push_back({ i,0 });
			if (map[i][w - 1] != '*')
				starts.push_back({ i,w - 1 });
		}
		
		int result = 0;
		vector<vector<bool>> isVisited(h, vector<bool>(w, false));
		for (int i = 0; i < starts.size(); i++)
		{
			if (isVisited[starts[i].y][starts[i].x])
				continue;

			isVisited[starts[i].y][starts[i].x] = true;

			queue<Pos> Q;
			Q.push(starts[i]);

			bool foundKey = false;

			while (!Q.empty())
			{
				int y = Q.front().y;
				int x = Q.front().x;
				Q.pop();

				if (map[y][x] == '$')
				{
					result++;
					map[y][x] = '.';
				}
				elif(among('A', map[y][x], 'Z'))
				{
					if (hasKey[map[y][x] - 'A'])
						map[y][x] = '.';
					else
						continue;
				}
				elif(among('a', map[y][x], 'z'))
				{
					hasKey[map[y][x] - 'a'] = true;
					map[y][x] = '.';

					foundKey = true;
				}

				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny < 0 || ny >= h || nx < 0 || nx >= w)
						continue;
					if (map[ny][nx] == '*' || isVisited[ny][nx])
						continue;

					isVisited[ny][nx] = true;
					Q.push({ ny,nx });
				}
				
			}
			if (foundKey)
			{
				fill(stoe(isVisited), vector<bool>(w, 0));
				i = -1;
			}
		}
		Cout result Endl;
	}
}