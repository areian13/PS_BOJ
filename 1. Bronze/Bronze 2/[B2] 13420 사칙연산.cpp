#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Op(long long a, char op, long long b)
{
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        long long a, b, c;
        char op, e;
        cin >> a >> op >> b >> e >> c;

        cout << (Op(a, op, b) == c ? "correct" : "wrong answer") << '\n';
    }
}