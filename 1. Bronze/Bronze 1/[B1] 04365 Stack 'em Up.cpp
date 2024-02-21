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

	array<string, 4> suit = { "Clubs","Diamonds","Hearts","Spades" };
	array<string, 13> value = { "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };

	int n;
	Cin n;

	vector<array<int, 52>> suffle(n);
	For(n)
	{
		Forj(52)
		{
			Cin suffle[i][j];
			suffle[i][j]--;
		}
	}

	array<int, 52> deck;
	For(52)
		deck[i] = i;

	while (true)
	{
		int k;
		Cin k;

		if (cin.eof())
			break;

		k--;
		array<int, 52> temp;
		For(52)
			temp[i] = deck[suffle[k][i]];
		deck = temp;

		For(52)
			printf("%s of %s\n", value[deck[i] % 13].c_str(), suit[deck[i] / 13].c_str());
		printf("\n");
	}
}