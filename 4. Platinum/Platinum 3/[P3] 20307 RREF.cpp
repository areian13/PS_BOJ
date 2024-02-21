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

class BigInteger
{
private:
    vector<int> num;
    bool isNegative;

    void RemoveLeadingZeros()
    {
        while (num.size() > 1 && num.back() == 0)
            num.pop_back();
        if (num.size() == 1 && num[0] == 0)
            isNegative = false;
    }
    int GetDigit(int i) const
    {
        if (i < 0 || i >= num.size())
            return 0;
        return num[i];
    }
public:
    BigInteger()
    {
        num.push_back(0);
        isNegative = false;
    }
    BigInteger(const string& strNum)
    {
        isNegative = (strNum[0] == '-');


        num.resize(strNum.size() - isNegative);
        for (int i = 0; i < num.size(); i++)
            num[i] = strNum[strNum.size() - i - 1] - '0';

        if (num.empty())
            num.push_back(0);

        RemoveLeadingZeros();
    }
    BigInteger(long long x)
    {
        if (x < 0)
        {
            isNegative = true;
            x = -x;
        }
        else
            isNegative = false;

        while (x > 0)
        {
            num.push_back(x % 10);
            x /= 10;
        }
        if (num.empty())
            num.push_back(0);
    }

    int Size() const
    {
        return num.size();
    }
    friend BigInteger abs(BigInteger& a)
    {
        BigInteger result = a;
        result.isNegative = false;
        return result;
    }

    const BigInteger operator+() const
    {
        return *this;
    }
    const BigInteger operator-() const
    {
        BigInteger result = *this;
        result.isNegative = !result.isNegative;
        return result;
    }

    friend BigInteger operator+(const BigInteger& a, const BigInteger& b)
    {
        if (a.isNegative != b.isNegative)
            return a - (-b);

        BigInteger result;
        int carry = 0;
        int size = max(a.Size(), b.Size());
        result.num.resize(size);
        for (int i = 0; i < size; i++)
        {
            int sum = a.GetDigit(i) + b.GetDigit(i) + carry;
            result.num[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0)
            result.num.push_back(carry);
        result.isNegative = a.isNegative;
        result.RemoveLeadingZeros();
        return result;
    }
    friend BigInteger operator-(const BigInteger& a, const BigInteger& b)
    {
        if (a.isNegative != b.isNegative)
            return a + (-b);
        if (a.isNegative && b.isNegative)
            return (-b) - (-a);
        if (a < b)
            return -(b - a);

        BigInteger result;
        int borrow = 0;
        int size = a.Size();
        result.num.resize(size);
        for (int i = 0; i < size; i++)
        {
            int diff = a.GetDigit(i) - b.GetDigit(i) - borrow;
            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
                borrow = 0;
            result.num[i] = diff;
        }
        result.isNegative = a.isNegative;
        result.RemoveLeadingZeros();
        return result;
    }
    friend BigInteger operator*(const BigInteger& a, const BigInteger& b)
    {
        BigInteger result;
        result.num.resize(a.Size() + b.Size());

        for (int i = 0; i < a.Size(); i++)
        {
            int carry = 0;
            for (int j = 0; j < b.Size(); j++)
            {
                int sum = a.GetDigit(i) * b.GetDigit(j) + result.num[i + j] + carry;
                carry = sum / 10;
                result.num[i + j] = sum % 10;
            }
            if (carry > 0) {
                result.num[i + b.Size()] += carry;
            }
        }

        result.isNegative = (a.isNegative != b.isNegative);
        result.RemoveLeadingZeros();
        return result;
    }
    friend BigInteger operator/(const BigInteger& a, const BigInteger& b)
    {
        if (b == 0)
            throw invalid_argument("Division by zero");

        BigInteger result, current;
        result.num.resize(a.Size());

        for (int i = a.Size() - 1; i >= 0; i--)
        {
            current.num.insert(current.num.begin(), a.GetDigit(i));
            current.RemoveLeadingZeros();

            int x = 0, l = 0, r = 10;
            while (l <= r)
            {
                int mid = (l + r) / 2;

                if (b * mid <= current)
                {
                    x = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            result.num[i] = x;
            current = current - b * x;
        }

        result.isNegative = (a.isNegative != b.isNegative);
        result.RemoveLeadingZeros();
        return result;
    }
    friend BigInteger operator%(const BigInteger& a, const BigInteger& b)
    {
        if (b == 0)
            throw invalid_argument("Division by zero");

        BigInteger result;

        for (int i = a.Size() - 1; i >= 0; i--)
        {
            result.num.insert(result.num.begin(), a.GetDigit(i));
            result.RemoveLeadingZeros();

            int x = 0, l = 0, r = 10;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (b * mid <= result) {
                    x = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            result = result - b * x;
        }

        result.isNegative = a.isNegative;
        result.RemoveLeadingZeros();
        return result;
    }

    friend void operator+=(BigInteger& a, const BigInteger& b)
    {
        a = a + b;
    }
    friend void operator-=(BigInteger& a, const BigInteger& b)
    {
        a = a - b;
    }
    friend void operator*=(BigInteger& a, const BigInteger& b)
    {
        a = a * b;
    }
    friend void operator/=(BigInteger& a, const BigInteger& b)
    {
        a = a / b;
    }
    friend void operator%=(BigInteger& a, const BigInteger& b)
    {
        a = a % b;
    }

    friend bool operator==(const BigInteger& a, const BigInteger& b)
    {
        if (a.isNegative != b.isNegative || a.Size() != b.Size())
            return false;

        for (int i = 0; i < a.Size(); i++)
        {
            if (a.num[i] != b.num[i])
                return false;
        }
        return true;
    }
    friend bool operator!=(const BigInteger& a, const BigInteger& b)
    {
        return !(a == b);
    }
    friend bool operator< (const BigInteger& a, const BigInteger& b)
    {
        if (a.isNegative != b.isNegative)
            return a.isNegative;
        if (a.Size() != b.Size())
            return (a.isNegative ? a.Size() > b.Size() : a.Size() < b.Size());
        for (int i = a.Size() - 1; i >= 0; i--)
        {
            if (a.GetDigit(i) != b.GetDigit(i))
                return (a.isNegative ? a.GetDigit(i) > b.GetDigit(i) : a.GetDigit(i) < b.GetDigit(i));
        }
        return false;
    }
    friend bool operator<=(const BigInteger& a, const BigInteger& b)
    {
        return (a < b || a == b);
    }
    friend bool operator> (const BigInteger& a, const BigInteger& b)
    {
        return !(a <= b);
    }
    friend bool operator>=(const BigInteger& a, const BigInteger& b)
    {
        return (a > b) || (a == b);
    }

    friend istream& operator>>(istream& is, BigInteger& x)
    {
        string s;
        is >> s;
        x = BigInteger(s);
        return is;
    }
    friend ostream& operator<<(ostream& os, const BigInteger& x)
    {
        if (x.isNegative)
            os << '-';
        for (int i = x.num.size() - 1; i >= 0; i--)
            os << x.num[i];
        return os;
    }
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

public:
    T p, q;

    Fraction(T p = 0, T q = 1) : p(p), q(q)
    {
        Init();
    }
    T GCD(T a, T b)
    {
        if (b == 0)
            return a;
        return GCD(b, a % b);
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
            f.p = (T)(stoll(value.substr(0, idx)));
            idx++;
            f.q = (T)(stoll(value.substr(idx, value.size() - idx)));
        }
        else
            f.p = (T)(stoll(value));

        f.Init();

        return is;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f)
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

    bool isREF = false;
    bool isRREF = false;

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
    Matrix2D(int m, int n) : size({ m,n })
    {
        matrix.resize(m, vector<T>(n, (T)0));
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
        isREF = true;
    }
    void RREF()
    {
        if (isRREF)
            return;
        if (!isREF)
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
        isRREF = true;
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

    friend void operator+=(Matrix2D& a, const Matrix2D& b)
    {
        a = a + b;
    }
    friend void operator-=(Matrix2D& a, const Matrix2D& b)
    {
        a = a - b;
    }

    friend Matrix2D operator*(const Matrix2D& a, T b)
    {
        Matrix2D result(a.Size().m, a.Size().n);
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
        return a * ((T)1 / b);
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
    friend ostream& operator<<(ostream& os, Matrix2D& m)
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

    int m, n;
    Cin m >> n;

    Matrix2D<Fraction<BigInteger>> matrix(m, n);
    Cin matrix;
    matrix.RREF();
    Cout matrix;
}