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
#include <stdio.h>
#include <stdlib.h>
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
#include <random>
#include <type_traits>

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

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
struct Fraction
{
private:
	int FindSlash(const string& value)
	{
		for (int i = 0; value[i] != '\0'; i++)
		{
			if (value[i] == '/')
				return i;
		}
		return -1;
	}
	T GCD(T a, T b)
	{
		if (b == 0)
			return a;
		return GCD(b, a % b);
	}

public:
	T p, q;

	Fraction(T p = 0, T q = 1) : p(p), q(q)
	{
		Init();
	}

	void Init()
	{
		T gcd = GCD(abs(p), abs(q));
		p /= gcd;
		q /= gcd;

		if (p >= 0 && q < 0)
		{
			p *= -1;
			q *= -1;
		}
	}
	T CastStrtoInt(string str)
	{
		if constexpr (is_same_v<T, int>)
			return stoi(str);
		else if constexpr (is_same_v<T, long long>)
			return stoll(str);
		else
			return str;
	}

	const Fraction operator+() const
	{
		return *this;
	}
	const Fraction operator-() const
	{
		return (Fraction)(-1) * (*this);
	}

	friend Fraction operator+(const Fraction& a, const Fraction& b)
	{
		Fraction result;
		result.p = a.p * b.q + b.p * a.q;
		result.q = a.q * b.q;
		result.Init();
		return result;
	}
	friend Fraction operator-(const Fraction& a, const Fraction& b)
	{
		Fraction result;
		result.p = a.p * b.q - b.p * a.q;
		result.q = a.q * b.q;
		result.Init();
		return result;
	}
	friend Fraction operator*(const Fraction& a, const Fraction& b)
	{
		Fraction result;
		result.p = a.p * b.p;
		result.q = a.q * b.q;
		result.Init();
		return result;
	}
	friend Fraction operator/(const Fraction& a, const Fraction& b)
	{
		Fraction result;
		result.p = a.p * b.q;
		result.q = a.q * b.p;
		result.Init();
		return result;
	}

	friend void operator+=(Fraction& a, const Fraction& b)
	{
		a.p = a.p * b.q + b.p * a.q;
		a.q = a.q * b.q;
		a.Init();
	}
	friend void operator-=(Fraction& a, const Fraction& b)
	{
		a.p = a.p * b.q - b.p * a.q;
		a.q = a.q * b.q;
		a.Init();
	}
	friend void operator*=(Fraction& a, const Fraction& b)
	{
		a.p = a.p * b.p;
		a.q = a.q * b.q;
		a.Init();
	}
	friend void operator/=(Fraction& a, const Fraction& b)
	{
		a.p = a.p * b.q;
		a.q = a.q * b.p;
		a.Init();
	}

	friend bool operator==(const Fraction& a, const Fraction& c)
	{
		return a.p == c.p && a.q == c.q;
	}
	friend bool operator!=(const Fraction& a, const Fraction& c)
	{
		return !(a == c);
	}
	friend bool operator< (const Fraction& a, const Fraction& c)
	{
		return a.p * c.q < c.p * a.q;
	}
	friend bool operator<=(const Fraction& a, const Fraction& c)
	{
		return (a < c) || (a == c);
	}
	friend bool operator> (const Fraction& a, const Fraction& c)
	{
		return !(a <= c);
	}
	friend bool operator>=(const Fraction& a, const Fraction& c)
	{
		return !(a < c);
	}

	friend istream& operator>>(istream& is, Fraction& f)
	{
		string value;
		is >> value;

		int idx = f.FindSlash(value);
		if (idx != -1)
		{
			f.p = f.CastStrtoInt(value.substr(0, idx));
			idx++;
			f.q = f.CastStrtoInt(value.substr(idx, value.size() - idx));
		}
		else
			f.p = f.CastStrtoInt(value);

		f.Init();

		return is;
	}
	friend ostream& operator<<(ostream& os, const Fraction f)
	{
		os << f.p;
		if (f.q != 1)
			os << '/' << f.q;
		return os;
	}
};

int main()
{
	FastIO;

	Fraction<int> a, b;
	Cin a.p >> a.q >> b.p >> b.q;

	Fraction<int> result = a + b;
	Cout result.p spc result.q Endl;
}