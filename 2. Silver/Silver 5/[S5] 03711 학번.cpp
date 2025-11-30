#include <iostream>
#include <vector>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int g;
        cin >> g;

        vector<int> sn(g);
        for (int i = 0; i < g; i++)
            cin >> sn[i];

        int result = g;
        while (true)
        {
            set<int> s;
            bool flag = true;
            for (int i = 0; i < g; i++)
            {
                if (s.count(sn[i] % result) == 1)
                {
                    flag = false;
                    break;
                }
                s.insert(sn[i] % result);
            }

            if (flag)
                break;
            result++;
        }
        cout << result << '\n';
    }
}