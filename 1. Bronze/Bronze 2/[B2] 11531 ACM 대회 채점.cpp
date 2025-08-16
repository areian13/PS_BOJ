#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<array<int, 3>, 26> log = { 0, };
    while (true)
    {
        int m;
        cin >> m;

        if (m == -1)
            break;

        char k;
        string t;
        cin >> k >> t;

        log[k - 'A'][0] = (t == "right");
        log[k - 'A'][1] = m;
        log[k - 'A'][2]++;
    }

    int cnt = 0, value = 0;
    for (int i = 0; i < 26; i++)
    {
        if (log[i][0])
        {
            cnt++;
            value += log[i][1] + (log[i][2] - 1) * 20;
        }
    }
    cout << cnt << ' ' << value << '\n';
}