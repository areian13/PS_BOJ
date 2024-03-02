#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, m, k;
        cin >> n >> m >> k;

        if (n == 0 && m == 0 && k == 0)
            break;

        vector<int> stitch(k);
        for (int i = 0; i < k; i++)
            cin >> stitch[i];

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            result += n;
            n += stitch[i % k];
        }
        cout << result << '\n';
    }
}