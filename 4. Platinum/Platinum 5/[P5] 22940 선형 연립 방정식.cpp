#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

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
		return a.p * c.q < c.p* a.q;
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

struct Size2D
{
	int m, n;

	bool operator==(Size2D c)
	{
		return m == c.m && n == c.n;
	}
	bool operator!=(Size2D c)
	{
		return !(*this == c);
	}
};

template <typename T>
class Matrix2D
{
private:
	vector<vector<T>> matrix;
	Size2D size;

	int FindNotZeroCol(int start)
	{
		for (int col = 0; col < size.n; col++)
		{
			for (int row = start; row < size.m; row++)
			{
				if (matrix[row][col] != (T)0)
					return col;
			}
		}
		return -1;
	}
	int FindNotZeroRow(int start, int col)
	{
		for (int row = start; row < size.m; row++)
		{
			if (matrix[row][col] != (T)0)
				return row;
		}
		return -1;
	}

public:
	Matrix2D() : size({ 0,0 })
	{
		matrix.resize(0, vector<T>(0, (T)0));
	}
	Matrix2D(int m, int n) : size({ m,n })
	{
		matrix.resize(m, vector<T>(n, (T)0));
	}
	Matrix2D(Size2D size) : size(size)
	{
		matrix.resize(size.m, vector<T>(size.n, (T)0));
	}

	void Resize(int m, int n)
	{
		size = { m, n };
		matrix.resize(m, vector<T>(n, (T)0));
	}
	void Resize(Size2D size)
	{
		::size = size;
		matrix.resize(size.m, vector<T>(size.n, (T)0));
	}

	void E_ij(int i, int j)
	{
		swap(matrix[i], matrix[j]);
	}
	void E_ij(int i, int j, T c)
	{
		for (int k = 0; k < size.n; k++)
			matrix[j][k] += c * matrix[i][k];
	}
	void E_i(int i, T c)
	{
		for (T& component : matrix[i])
			component *= c;
	}

	const Matrix2D I()
	{
		Matrix2D result(size.m, size.n);
		for (int i = 0; i < min(size.m, size.n); i++)
		{
			result[i][i] = 1;
		}
		return result;
	}
	const Matrix2D I(int m)
	{
		Matrix2D result(m, m);
		for (int i = 0; i < m; i++)
		{
			result[i][i] = T(1);
		}
		return result;
	}
	const Matrix2D I(int m, int n)
	{
		Matrix2D result(m, n);
		for (int i = 0; i < min(m, n); i++)
		{
			result[i][i] = T(1);
		}
		return result;
	}
	const Matrix2D I(Size2D size)
	{
		Matrix2D result(size);
		for (int i = 0; i < min(size.m, size.n); i++)
		{
			result[i][i] = T(1);
		}
		return result;
	}

	const Matrix2D O()
	{
		Matrix2D result(size.m, size.n);
		return result;
	}
	const Matrix2D O(int m)
	{
		Matrix2D result(m, m);
		return result;
	}
	const Matrix2D O(int m, int n)
	{
		Matrix2D result(m, n);
		return result;
	}
	const Matrix2D O(Size2D size)
	{
		Matrix2D result(size);
		return result;
	}

	const Matrix2D Jeonchi()
	{
		Matrix2D result(size.n, size.m);
		for (int row = 0; row < size.n; row++)
		{
			for (int col = 0; col < size.m; col++)
			{
				result[row][col] = matrix[col][row];
			}
		}
		return result;
	}

	void REF()
	{
		int start = 0;
		while (start < size.m)
		{
			int notZeroCol = FindNotZeroCol(start);
			if (notZeroCol == -1)
			{
				start++;
				continue;
			}

			int notZeroRow = FindNotZeroRow(start, notZeroCol);
			if (notZeroRow == -1)
			{
				start++;
				continue;
			}

			E_ij(start, notZeroRow);
			E_i(start, (T)1 / matrix[start][notZeroCol]);
			for (int row = start + 1; row < size.m; row++)
				E_ij(start, row, -matrix[row][notZeroCol]);
			start++;
		}
	}
	void RREF()
	{
		REF();
		for (int row = 0; row < size.m; row++)
		{
			for (int col = 0; col < size.n; col++)
			{
				if (matrix[row][col] == (T)1)
				{
					for (int k = 0; k < row; k++)
						E_ij(row, k, -matrix[k][col]);
					break;
				}
			}
		}
	}

	friend Matrix2D pow(Matrix2D a, long long n)
	{
		Matrix2D result = Matrix2D<T>{}.I(a.Size());
		while (n > 0)
		{
			if (n % 2 == 1)
				result *= a;
			a *= a;
			n /= 2;
		}
		return result;
	}

	Size2D Size() const
	{
		return size;
	}

	const Matrix2D operator+() const
	{
		return *this;
	}
	const Matrix2D operator-() const
	{
		return (*this * (-1));
	}

	friend Matrix2D operator+(const Matrix2D& a, const Matrix2D& b)
	{
		if (a.Size() != b.Size())
			throw invalid_argument("The size of the two matrices is different.");

		Matrix2D<T> result(a.Size().m, a.Size().n);
		for (int row = 0; row < a.Size().m; row++)
		{
			for (int col = 0; col < a.Size().n; col++)
			{
				result[row][col] = a.matrix[row][col] + b.matrix[row][col];
			}
		}
		return result;
	}
	friend Matrix2D operator-(const Matrix2D& a, const Matrix2D& b)
	{
		return a + (-b);
	}
	friend Matrix2D operator*(const Matrix2D& a, const Matrix2D& b)
	{
		if (a.Size().n != b.Size().m)
			throw invalid_argument("The size of left matrix's n and right matrix's m is different.");

		Matrix2D result(a.Size().m, b.Size().n);
		for (int i = 0; i < a.Size().m; i++)
		{
			for (int j = 0; j < b.Size().n; j++)
			{
				for (int k = 0; k < a.Size().n; k++)
				{
					result[i][j] += a.matrix[i][k] * b.matrix[k][j];
				}
			}
		}
		return result;
	}

	friend void operator+=(Matrix2D& a, const Matrix2D& b)
	{
		a = a + b;
	}
	friend void operator-=(Matrix2D& a, const Matrix2D& b)
	{
		a = a - b;
	}
	friend void operator*=(Matrix2D& a, const Matrix2D& b)
	{
		a = a * b;
	}


	friend Matrix2D operator*(const Matrix2D& a, T b)
	{
		Matrix2D result(a.Size());
		for (int row = 0; row < a.Size().m; row++)
		{
			for (int col = 0; col < a.Size().n; col++)
			{
				result[row][col] = a.matrix[row][col] * b;
			}
		}
		return result;
	}
	friend Matrix2D operator/(const Matrix2D& a, T b)
	{
		Matrix2D result(a.Size());
		for (int row = 0; row < a.Size().m; row++)
		{
			for (int col = 0; col < a.Size().n; col++)
			{
				result[row][col] = a.matrix[row][col] / b;
			}
		}
		return result;
	}
	friend Matrix2D operator%(const Matrix2D& a, T b)
	{
		Matrix2D result(a.Size());
		for (int row = 0; row < a.Size().m; row++)
		{
			for (int col = 0; col < a.Size().n; col++)
			{
				result[row][col] = a.matrix[row][col] % b;
			}
		}
		return result;
	}

	friend Matrix2D operator*(T b, Matrix2D& a)
	{
		return a * b;
	}

	vector<T>& operator[](int i)
	{
		return matrix[i];
	}
	const vector<T>& operator[](int i) const
	{
		return matrix[i];
	}

	T& operator()(int row, int col)
	{
		return matrix[row][col];
	}
	const T& operator()(int row, int col) const
	{
		return matrix[row][col];
	}

	friend istream& operator>>(istream& is, Matrix2D& m)
	{
		for (vector<T>& row : m.matrix)
		{
			for (T& component : row)
			{
				is >> component;
			}
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, Matrix2D m)
	{
		for (vector<T>& row : m.matrix)
		{
			for (T& component : row)
			{
				os << component << ' ';
			}
			os << '\n';
		}
		return os;
	}
};

int main()
{
	FastIO;

	int n;
	Cin n;

	Matrix2D<Fraction<long long>> mat(n, n + 1);
	Cin mat;
	mat.RREF();
	For(n)
		Cout mat[i][n] fspc;
}