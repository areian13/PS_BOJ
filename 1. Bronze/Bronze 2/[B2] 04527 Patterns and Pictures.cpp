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
        int n;
        cin >> n;

        int total = 0;
        for (int i = 0; i < n; i++)
        {
            int s, r;
            cin >> s >> r;

            total += s * r;
        }

        for (int y = 1; y <= 3; y++)
        {
            int result = 1296 * y / total;
            cout << result << ' ';
        }
    }
}