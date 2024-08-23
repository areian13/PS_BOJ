#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> result(n + m, 0);
    for (int i = 0; i < n; i++)
    {
        result[i] += s[i];
        for (int j = 0; j < n + m; j++)
        {
            int t;
            cin >> t;

            result[j] += t;
            result[i] -= t;
        }
    }

    for (int i = 0; i < n + m; i++)
        cout << result[i] << ' ';
    cout << '\n';
}