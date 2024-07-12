#include <iostream>
#include <vector>
#include <stack>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

double Calc(double a, double b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    return a / b;
}

double CalcPostfix(string& e, vector<int>& a)
{
    stack<double> S;
    for (char c : e)
    {
        if ('A' <= c && c <= 'Z')
            S.push(a[c - 'A']);
        else
        {
            double b = S.top();
            S.pop();
            double a = S.top();
            S.pop();

            S.push(Calc(a, b, c));
        }
    }

    return S.top();
}

int main()
{
    FastIO;

    int n;
    string e;
    cin >> n >> e;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    lf(2);
    double result = CalcPostfix(e, a);
    cout << result << '\n';
}