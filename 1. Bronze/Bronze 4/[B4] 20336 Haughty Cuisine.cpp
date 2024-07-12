#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        cout << m << '\n';
        for (int j = 0; j < m; j++)
        {
            string food;
            cin >> food;

            cout << food << '\n';
        }
        break;
    }
}