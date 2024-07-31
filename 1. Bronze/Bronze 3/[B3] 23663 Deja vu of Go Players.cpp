#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
        }
        for (int i = 0; i < m; i++)
        {
            int b;
            cin >> b;
        }

        string result = (n <= m ? "Yes" : "No");
        cout << result << '\n';
    }
}