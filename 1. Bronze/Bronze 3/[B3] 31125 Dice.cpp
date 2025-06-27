#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int s, n, f, m;
        cin >> s >> n >> f >> m;

        bool result = (n + m <= s && s <= f * n + m);
        if (result == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}