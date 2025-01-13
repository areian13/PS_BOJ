#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanSort(int k, vector<int>& a)
{
    int n = a.size();

    vector<bool> isVisited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (isVisited[i])
            continue;

        vector<int> indices;
        queue<int> Q;
        Q.push(i);
        isVisited[i] = true;

        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            indices.push_back(u);

            int v = (u + k) % n;
            if (isVisited[v])
                continue;

            isVisited[v] = true;
            Q.push(v);
        }

        int m = indices.size();
        vector<int> values(m);
        for (int j = 0; j < m; j++)
            values[j] = a[indices[j]];

        sort(values.begin(), values.end());
        sort(indices.begin(), indices.end());

        for (int j = 0; j < m; j++)
            a[indices[j]] = values[j];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != i)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    bool result = CanSort(k, a);
    if (result == true)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}