#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Make3k(int idx, string& p)
{
    int n = p.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (p[i] - '0');

    if (n == 1) p = "6";
    else
    {
        int v = (p[idx] - '0') + (3 - sum % 3);
        if (v >= 10)
            v -= 3;
        p[idx] = v + '0';
    }
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        string p;
        cin >> n >> p;

        for (int i = 0; i < n; i++)
        {
            int u = p[i];
            Make3k(i, p);
            cout << p << ' ' << 3 << '\n';
            p[i] = u;
        }
    }
}