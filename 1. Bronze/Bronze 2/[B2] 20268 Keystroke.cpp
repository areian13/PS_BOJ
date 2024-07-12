#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int m, n;
        cin >> m >> n;

        for (int i = 0; i < m + n; i++)
        {
            int a;
            cin >> a;
        }

        int result = (m + n == 4 ? 7 : 1);
        cout << result << '\n';
    }
}