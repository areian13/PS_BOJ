#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cfloat>
#include <cstring>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

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

bool IsMo(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void PrintPWD(int k, string& pwd, int mo, int ja, int l, vector<char>& code)
{
	int c = code.size();

	if (pwd.size() == l)
	{
		if (mo >= 1 && ja >= 2)
			cout << pwd << '\n';
		return;
	}

	for (int i = k; i < c; i++)
	{
		pwd += code[i];
		PrintPWD(i + 1, pwd, mo + IsMo(code[i]), ja + !IsMo(code[i]), l, code);
		pwd.pop_back();
	}
}

int main()
{
	FastIO;

	int l, c;
	cin >> l >> c;

	vector<char> code(c);
	For(c)
		Cin code[i];
	sort(code.begin(), code.end());

	string pwd;
	PrintPWD(0, pwd, 0, 0, l, code);
}