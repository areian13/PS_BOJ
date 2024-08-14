#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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
    int Size() const
    {
        return num.size();
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
    ~BigInteger()
    {
        num.clear();
        isNegative = false;
    }

    friend BigInteger abs(BigInteger& a)
    {
        BigInteger result = a;
        result.isNegative = false;
        return result;
    }
    friend BigInteger pow(BigInteger a, BigInteger n)
    {
        BigInteger result = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
                result *= a;
            a *= a;
            n /= 2;
        }
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

    BigInteger& operator++()
    {
        *this += 1;
        return *this;
    }
    BigInteger& operator--()
    {
        *this -= 1;
        return *this;
    }

    BigInteger operator++(int)
    {
        BigInteger temp = *this;
        *this += 1;
        return temp;
    }
    BigInteger operator--(int)
    {
        BigInteger temp = *this;
        *this -= 1;
        return temp;
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
    friend ostream& operator<<(ostream& os, const BigInteger x)
    {
        if (x.isNegative)
            os << '-';
        for (int i = x.num.size() - 1; i >= 0; i--)
            os << x.num[i];
        return os;
    }

};

int main()
{
    FastIO;

    BigInteger a, b;
    cin >> a >> b;

    BigInteger result = a + b;
    cout << result << '\n';
}