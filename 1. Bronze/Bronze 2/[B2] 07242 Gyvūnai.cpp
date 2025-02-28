#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX (60 * 24)

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, MAX> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        int sh, sm, eh, em;
        cin >> sh >> sm >> eh >> em;

        for (int t = sh * 60 + sm; t < eh * 60 + em; t++)
            cnt[t]++;
    }

    int s = -1, e = -1;
    for (int t = 0; t < MAX; t++)
    {
        if (cnt[t] == n)
        {
            s = (s == -1 ? t : s);
            e = t + 1;
        }
    }

    if (s != -1)
    {
        cout << "TAIP" << '\n';
        cout << s / 60 << ' ' << s % 60 << ' ' << e / 60 << ' ' << e % 60 << '\n';
    }
    else
        cout << "NE" << '\n';
}