#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int v, w;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        for (int j = 0; j < p; j++)
        {
            int a, d;
            cin >> a >> d;
            graph[i].push_back({ a - 1,d });
        }
    }

    int result = INF;
    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        seq[i] = i;
    do
    {
        vector<int> t = c;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += t[seq[i]];
            for (auto& [v, w] : graph[seq[i]])
                t[v] = max(t[v] - w, 1);
        }
        result = min(result, sum);
    } while (next_permutation(seq.begin(), seq.end()));
    cout << result << '\n';
}