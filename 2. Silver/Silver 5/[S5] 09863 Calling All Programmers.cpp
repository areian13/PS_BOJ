#include <iostream>
#include <queue>

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

        queue<int> Q;
        for (int i = 1; i <= n; i++)
            Q.push(i);

        int result = -1;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                Q.push(Q.front());
                Q.pop();
            }

            result = Q.front();
            Q.pop();
        }
        cout << result << '\n';
    }
}