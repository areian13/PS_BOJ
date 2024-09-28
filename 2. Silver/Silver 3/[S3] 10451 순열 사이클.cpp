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

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        vector<bool> isVisited(n + 1, false);
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = i;
            if (isVisited[x])
                continue;

            while (!isVisited[x])
            {
                isVisited[x] = true;
                x = p[x];
            }
            result++;
        }
        cout << result << '\n';
    }
}