#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Add(long long a, long long b, long long pre)
{
    return (a + b) - pre;
}

long long Sub(long long a, long long b, long long pre)
{
    return (a - b) * pre;
}
long long Mul(long long a, long long b)
{
    return pow(a * b, 2);
}
long long Div(long long a)
{
    return (a + 1) / 2;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = 1;
    while (n--)
    {
        long long a, b;
        char op;
        cin >> a >> op >> b;

        switch (op)
        {
        case '+':
            result = Add(a, b, result);
            break;
        case '-':
            result = Sub(a, b, result);
            break;
        case '*':
            result = Mul(a, b);
            break;
        case '/':
            result = Div(a);
            break;
        }
        cout << result << '\n';
    }
}