
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

array<string, 8> codes = { "000000","001111","010011","011100","100110","101001","110101","111010" };

int CountDiff(string code, int idx)
{
	int result = 0;
	For(6)
		result += (code[i] != codes[idx][i]);
	return result;
}

int SimilarCodeNum(string code)
{
	For(8)
	{
		if (CountDiff(code, i) <= 1)
			return i;
	}
	return -1;
}

int main()
{
	FastIO;


	int n;
	Cin n;

	string letter;
	Cin letter;

	string result;
	for (int i = 0; i < letter.size(); i += 6)
	{
		int codeNum = SimilarCodeNum(letter.substr(i, 6));
		if (codeNum != -1)
			result += 'A' + codeNum;
		else
		{
			result = to_string(i / 6 + 1);
			break;
		}
	}
	Cout result Endl;
}