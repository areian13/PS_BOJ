#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int k;
        cin >> k;

        if (k == 0)
            break;

        int m;
        cin >> m;

        unordered_map<int, bool> isHeard;
        for (int i = 0; i < k; i++)
        {
            int num;
            cin >> num;

            isHeard[num] = true;
        }

        bool isClear = true;
        for (int i = 0; i < m; i++)
        {
            int c, r;
            cin >> c >> r;

            int cnt = 0;
            for (int j = 0; j < c; j++)
            {
                int num;
                cin >> num;

                cnt += isHeard[num];
            }
            isClear &= (cnt >= r);
        }

        string result = (isClear ? "yes" : "no");
        cout << result << '\n';
    }
}