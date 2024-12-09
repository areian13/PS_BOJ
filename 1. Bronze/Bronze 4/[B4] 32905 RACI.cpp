#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    bool result = true;
    for (int i = 0; i < n; i++)
    {
        int cntA = 0;
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;

            cntA += (c == 'A');
        }
        result &= (cntA == 1);
    }

    if (result == true)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}