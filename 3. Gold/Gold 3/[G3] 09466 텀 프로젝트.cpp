#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DFS(int cur, int& result, vector<int>& stu, vector<bool>& madeTeam, vector<bool>& isVisited)
{
    if (isVisited[cur])
        return;
    isVisited[cur] = true;

    int nxt = stu[cur];
    if (!isVisited[nxt])
        DFS(nxt, result, stu, madeTeam, isVisited);
    else if (!madeTeam[nxt])
    {
        for (int x = nxt; x != cur; x = stu[x])
            result--;
        result--;
    }
    madeTeam[cur] = true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        vector<int> stu(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> stu[i];

        vector<bool> madeTeam(n + 1, false), isVisited(n + 1, false);
        int result = n;

        for (int i = 1; i <= n; i++)
            DFS(i, result, stu, madeTeam, isVisited);

        cout << result << '\n';
    }
}