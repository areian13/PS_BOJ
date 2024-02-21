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
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
	for (T& value : vec)
		os << value << ' ';
	return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
	for (T& value : vec)
		os << value << ' ';
	return os;
}

bool CanLearn(array<bool, 26>& learnSpell, array<bool, 26>& wordSpell)
{
	for (int i = 0; i < 26; i++)
	{
		if (wordSpell[i] && !learnSpell[i])
			return false;
	}
	return true;
}

int CountLearnWord(char lastSpell, array<bool, 26>& learnSpell, int l, int k, vector<array<bool, 26>>& wordsSpell)
{
	if (k < 5)
		return 0;

	int n = wordsSpell.size();

	if (l == k)
	{
		int result = 0;
		For(n)
			result += CanLearn(learnSpell, wordsSpell[i]);
		return result;
	}

	int result = 0;
	for (char c = lastSpell + 1; c <= 'z'; c++)
	{
		if (learnSpell[c - 'a'])
			continue;

		learnSpell[c - 'a'] = true;
		result = max(result, CountLearnWord(c, learnSpell, l + 1, k, wordsSpell));
		learnSpell[c - 'a'] = false;
	}
	return result;
}

int main()
{
	FastIO;

	int n, k;
	Cin n >> k;

	vector<string> words(n);
	vector<array<bool, 26>> wordsSpell(n, { false, });
	For(n)
	{
		Cin words[i];

		for (char spell : words[i])
			wordsSpell[i][spell - 'a'] = true;
	}

	array<bool, 26> learnSpell = { false, };
	learnSpell['a' - 'a'] = true;
	learnSpell['n' - 'a'] = true;
	learnSpell['t' - 'a'] = true;
	learnSpell['i' - 'a'] = true;
	learnSpell['c' - 'a'] = true;
	int result = CountLearnWord('a' - 1, learnSpell, 5, k, wordsSpell);
	Cout result Endl;
}