#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;

            result += min(m / n, a);
        }
        cout << result << '\n';
    }
}