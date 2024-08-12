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
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
                cout << 'X';
            cout << '\n';
        }
        cout << '\n';
    }
}