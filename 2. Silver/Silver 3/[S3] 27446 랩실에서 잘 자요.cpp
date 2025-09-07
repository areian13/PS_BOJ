#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<bool> has(n, false);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        has[k - 1] = true;
    }

    int result = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (!has[i])
        {
            l = (l == -1 ? i : l);
            r = i;
        }
        else
        {
            int j = 1;
            while (i + 1 < n && has[i + 1])
                i++, j++;

            if (j >= 3)
            {
                if (l != -1)
                {
                    result += 5 + (r - l + 1) * 2;
                    l = -1;
                }
            }
        }
    }
    if (l != -1)
        result += 5 + (r - l + 1) * 2;

    cout << result << '\n';
}