#include <iostream>
#include <vector>

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

        vector<int> u(n);
        for (int i = 0; i < n; i++)
            cin >> u[i];

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (u[i] != v[i]);
        cout << result << '\n';
    }
}