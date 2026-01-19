#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, q;
    cin >> n >> k >> q;
    q--;

    vector<pair<int, char>> chat(k);
    for (auto& [r, c] : chat)
        cin >> r >> c;

    int s = q;
    while (s >= 1 && chat[s - 1].first == chat[q].first)
        s--;

    vector<bool> read(n, false);
    read[0] = true;
    for (int i = s; i < k; i++)
    {
        auto& [r, c] = chat[i];
        read[c - 'A'] = true;
    }

    if (chat[q].first == 0)
        cout << -1 << '\n';
    else
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (!read[i])
            {
                cout << (char)(i + 'A') << ' ';
                flag = false;
            }
        }
        if (flag)
            cout << -1;
        cout << '\n';
    }
}