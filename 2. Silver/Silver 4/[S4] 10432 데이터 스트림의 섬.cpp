#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int n = 12;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int t;
        cin >> t;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int result = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i; j < n - 1; j++)
            {
                int c = a[i];
                for (int k = i; k <= j; k++)
                    c = min(c, a[k]);
                result += (c > a[i - 1] && c > a[j + 1]);
            }
        }
        cout << t << ' ' << result << '\n';
    }
}