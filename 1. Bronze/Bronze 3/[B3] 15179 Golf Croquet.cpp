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

	string a, b, record;
	int s;
	getline(cin, a);
	getline(cin, b);
	Cin s >> record;

	array<int, 2> score = { 0,0 };
	bool hasWinner = false;
	For(s)
	{
		int team = i % 2;
		int otherTeam = (i + 1) % 2;
		switch (record[i])
		{
		case 'H':
			score[team]++;
			break;

		case 'D':
			score[team] += 2;
			break;

		case 'O':
			score[otherTeam]++;
			break;
		}
		if (score[0] >= 7 || score[1] >= 7)
		{
			hasWinner = true;
			break;
		}
	}
	printf("%s %d %s %d. ", a.c_str(), min(score[0], 7), b.c_str(), min(score[1], 7));
	string winner = (score[0] > score[1] ? a : b);
	if (hasWinner)
		printf("%s has won.\n", winner.c_str());
	elif(score[0] != score[1])
		printf("%s is winning.\n", winner.c_str());
	else
		printf("All square.\n");
}