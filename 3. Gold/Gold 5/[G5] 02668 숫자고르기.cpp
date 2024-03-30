#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DFS(int cur, vector<bool>& isVisited, vector<set<int>>& sets, vector<int>& x)
{
    isVisited[cur] = true;
    sets[0].insert(cur);

    int nxt = x[cur];
    sets[1].insert(nxt);

    if (isVisited[nxt])
        return;

    DFS(nxt, isVisited, sets, x);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        x[i]--;
    }

    vector<int> result;
    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (isVisited[i])
            continue;

        vector<set<int>> sets(2);
        DFS(i, isVisited, sets, x);

        if (sets[0] == sets[1])
        {
            for (int v : sets[0])
                result.push_back(v);
        }
        else
        {
            for (int v : sets[0])
                isVisited[v] = false;
        }
    }
    sort(result.begin(), result.end());

    int m = result.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++)
        cout << result[i] + 1 << '\n';
}