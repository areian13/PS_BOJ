#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> k(m);
    for (int i = 0; i < m; i++)
        cin >> k[i];

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int v : k)
        {
            if (i % v == 0)
            {
                result += i;
                break;
            }
        }
    }
    cout << result << '\n';
}