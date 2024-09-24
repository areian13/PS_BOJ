#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = 0;
    int pos = 0;
    vector<int> poses;
    while (n--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int x;
            cin >> x;

            poses.push_back(x);
        }
        else
        {
            int p = poses.size();

            if (p == 0)
                continue;

            sort(poses.begin(), poses.end());
            int minDist = INT_MAX;
            int idx = 0;
            for (int i = 0; i < p; i++)
            {
                int dist = abs(pos - poses[i]);
                if (dist < minDist)
                {
                    minDist = dist;
                    idx = i;
                }
            }

            int l = idx;
            int r = idx + 1;
            while (l >= 0 || r < p)
            {
                int dl = (l == -1 ? INT_MAX : abs(pos - poses[l]));
                int dr = (r == p ? INT_MAX : abs(pos - poses[r]));

                if (dl <= dr)
                {
                    result += dl;
                    pos = poses[l];
                    l--;
                }
                else
                {
                    result += dr;
                    pos = poses[r];
                    r++;
                }
            }

            poses.clear();
        }
    }

    cout << result << '\n';
}