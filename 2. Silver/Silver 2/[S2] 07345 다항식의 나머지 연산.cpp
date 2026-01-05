#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void InputPoly(vector<int>& p)
{
    int n;
    cin >> n;
    p.resize(n);
    for (int i = n - 1; i >= 0; i--)
        cin >> p[i];
}
void PrintPoly(vector<int>& p)
{
    int n = p.size();
    cout << n << ' ';
    for (int i = n - 1; i >= 0; i--)
        cout << p[i] << ' ';
    cout << '\n';
}
void XOR(vector<int>& a, vector<int>& b, vector<int>& c)
{
    int n = a.size(), m = b.size();
    for (int i = 0; i < min(n, m); i++)
        c[i] = a[i] ^ b[i];
    for (int i = min(n, m); i < max(n, m); i++)
        c[i] = (n > m ? a : b)[i];
}
void Mul(vector<int>& a, vector<int>& b, vector<int>& c)
{
    int n = a.size(), m = b.size();
    c.resize(n + m - 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            c[i + j] += a[i] * b[j];
    }

    for (int i = 0; i < n + m - 1; i++)
        c[i] %= 2;
}
void Mod(vector<int>& a, vector<int>& b, vector<int>& c)
{
    c = a;
    while (c.size() >= b.size())
    {
        vector<int> t = b;
        reverse(t.begin(), t.end());
        t.resize(c.size(), 0);
        reverse(t.begin(), t.end());

        XOR(c, t, c);

        while (!c.empty() && c.back() == 0)
            c.pop_back();
    }
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        vector<int> f, g, h;
        InputPoly(f), InputPoly(g), InputPoly(h);

        vector<int> mul, result;
        Mul(f, g, mul);
        Mod(mul, h, result);

        PrintPoly(result);
    }
}