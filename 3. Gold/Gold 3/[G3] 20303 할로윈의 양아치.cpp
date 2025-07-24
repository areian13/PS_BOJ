#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Friend
{
    int root = -1;
    int candy = 0;
    int cnt = 1;
};

int Find(int a, vector<Friend>& p)
{
    if (p[a].root == a)
        return a;
    return p[a].root = Find(p[a].root, p);
}

void Union(int a, int b, vector<Friend>& p)
{
    a = Find(a, p);
    b = Find(b, p);

    p[max(a, b)].root = min(a, b);
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<Friend> friends(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> friends[i].candy;
        friends[i].root = i;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        Union(a, b, friends);
    }

    for (int i = 1; i <= n; i++)
    {
        if (friends[i].root == i)
            continue;

        int p = Find(i, friends);
        friends[p].candy += friends[i].candy;
        friends[p].cnt += friends[i].cnt;
    }

    vector<int> dp(k + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (friends[i].root != i)
            continue;

        for (int j = k; j > friends[i].cnt; j--)
            dp[j] = max(dp[j], dp[j - friends[i].cnt] + friends[i].candy);
    }

    int result = dp[k];
    cout << result << '\n';
}