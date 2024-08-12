#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int nx(int x, int d)
{
    return (x + 1) % d;
}

bool IsMo(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    unordered_map<string, int> dist;
    dist[s] = s.size();

    queue<string> Q;
    Q.push(s);

    while (!Q.empty())
    {
        string u = Q.front();
        int d = dist[u];
        Q.pop();

        if (d < 5)
            continue;

        for (int e = 0; e < d; e++)
        {
            vector<int> moIdx;
            vector<array<int, 2>> sameIdx;
            for (int i = 0; i < 5; i++)
            {
                int x = (e + i) % d;
                if (IsMo(u[x]))
                    moIdx.push_back(x);
                for (int j = 0; j < 5; j++)
                {
                    int y = (e + j) % d;
                    if (x == y)
                        continue;
                    if (u[x] == u[y])
                        sameIdx.push_back({ x,y });
                }
            }

            int m = moIdx.size();
            for (int i = 0; i < m - 2; i++)
            {
                for (int j = i + 1; j < m - 1; j++)
                {
                    for (int k = j + 1; k < m; k++)
                    {
                        array<int, 3> idx = { moIdx[i],moIdx[j],moIdx[k] };
                        sort(idx.begin(), idx.end());

                        string v = u;
                        v.erase(v.begin() + idx[2]);
                        v.erase(v.begin() + idx[1]);
                        v.erase(v.begin() + idx[0]);

                        if (dist.count(v) != 0)
                            continue;

                        dist[v] = v.size();
                        Q.push(v);
                    }
                }
            }

            int p = sameIdx.size();
            for (int i = 0; i < p; i++)
            {
                array<int, 2> idx = sameIdx[i];
                sort(idx.begin(), idx.end());

                string v = u;
                v.erase(v.begin() + idx[1]);
                v.erase(v.begin() + idx[0]);

                if (dist.count(v) != 0)
                    continue;

                dist[v] = v.size();
                Q.push(v);
            }
        }
    }

    int result = INT_MAX;
    for (auto it = dist.begin(); it != dist.end(); it++)
        result = min(result, it->second);
    cout << result << '\n';
}