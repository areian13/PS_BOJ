#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#ifdef ONLINE_JUDGE
#define __int128  __int128

ostream& operator<<(ostream& os, __int128 value)
{
    bool isNega = value < 0;
    if (isNega)
        value = -value;

    string result = "";
    do
    {
        result += (value % 10 + '0');
        value /= 10;
    } while (value > 0);

    if (isNega)
        result += '-';
    reverse(result.begin(), result.end());
    return os << result;
}

#else
#define __int128 long long
#endif

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
    cin >> m >> n;

    Matrix2D<Fraction<__int128>> matrix(m, n);
    cin >> matrix;
    matrix.RREF();
    cout << matrix << '\n';
}