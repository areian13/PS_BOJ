#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Fraction
{
    long long p, q;

    Fraction()
    {

    }
    Fraction(long long a)
    {
        p = a;
        q = 1;
    }
    Fraction(long long p, long long q)
    {
        this->p = p;
        this->q = q;
        Init();
    }

    void Init()
    {
        int g = gcd(p, q);
        p /= g;
        q /= g;
    }
    friend Fraction operator+(Fraction a, Fraction b)
    {
        long long p = a.p * b.q + b.p * a.q;
        long long q = a.q * b.q;

        return { p,q };
    }
    friend Fraction operator/(Fraction a, Fraction b)
    {
        long long p = a.p * b.q;
        long long q = a.q * b.p;

        return { p,q };
    }
};

bool IsValid(vector<Fraction>& stack)
{
    if (stack.size() < 4)
        return false;

    for (int i = 0; i < 3; i++)
    {
        if (stack[stack.size() - 1 - i].q == 0)
            return false;
    }
    return stack[stack.size() - 4].q == 0;
}

Fraction GetFraction(string& form)
{
    vector<Fraction> stack;

    for (char c : form)
    {
        if (c == '(')
            stack.push_back({ +1,0 });
        else if (c == ')')
        {
            if (!IsValid(stack))
                return { +1,0 };

            Fraction f3 = stack.back();
            stack.pop_back();
            Fraction f2 = stack.back();
            stack.pop_back();
            Fraction f1 = stack.back();
            stack.pop_back();
            stack.pop_back();

            Fraction f = f1 + f2 / f3;
            stack.push_back(f1 + f2 / f3);
        }
        else
            stack.push_back(Fraction(c - '0'));
    }
    if (stack.size() != 1)
        return { +1,0 };
    return stack.back();
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    string form(n, '\0');
    for (int i = 0; i < n; i++)
        cin >> form[i];

    Fraction result = GetFraction(form);
    if (result.q == 0)
        cout << -1 << '\n';
    else
        cout << result.p << ' ' << result.q << '\n';
}