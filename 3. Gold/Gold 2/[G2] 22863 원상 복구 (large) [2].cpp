#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n, k;
    cin >> n >> k;

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    vector<bool> isVisited(n + 1, false);
    vector<int> result(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (isVisited[i])
            continue;

        long long cnt = 0;
        vector<int> order(n + 1);
        for (int x = i; !isVisited[x]; x = d[x])
        {
            isVisited[x] = true;
            order[cnt] = x;
            cnt++;
        }

        for (long long j = 0; j < cnt; j++)
            result[order[(j + k) % cnt]] = s[order[j]];
    }

    for (int i = 1; i <= n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}