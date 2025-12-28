#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int sum = 0, maxP = 0;
    string name = "";
    for (int i = 0; i < n; i++)
    {
        string s;
        int k, m;
        cin >> s >> k >> m;

        int p = 0;
        while (k <= m)
            p++, m -= k - 2;

        if (p > maxP)
            maxP = p, name = s;
        sum += p;
    }

    cout << sum << '\n' << name << '\n';
}