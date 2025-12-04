#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        char c;
        cin >> n >> c;

        for (int i = 0; i < n; i++)
        {
            if (c == 'C')
            {
                char c;
                cin >> c;
                cout << (c - 'A' + 1) << ' ';
            }
            else
            {
                int n;
                cin >> n;
                cout << char(n - 1 + 'A') << ' ';
            }
        }
        cout << '\n';
    }
}