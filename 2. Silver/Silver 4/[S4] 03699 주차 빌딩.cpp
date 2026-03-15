#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int h, l;
        cin >> h >> l;

        vector<pair<int, int>> pos(h * l, { -1,-1 });
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < l; j++)
            {
                int s;
                cin >> s;
                if (s == -1)
                    continue;
                pos[s - 1] = { i,j };
            }
        }

        vector<int> belt(h, 0);
        int result = 0;
        for (auto& [i, j] : pos)
        {
            if (i == -1) break;
            
            int dist = abs(belt[i] - j);
            result += i * 20 + min(dist, l - dist) * 5;
            belt[i] = j;
        }
        cout << result << '\n';
    }
}