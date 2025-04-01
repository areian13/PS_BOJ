#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Ratio
{
    int a, b, p, q;
};

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int ArrayGCD(vector<int>& arr)
{
    int n = arr.size();

    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = GCD(result, arr[i]);
    return result;
}

void DFS(int u, int p, vector<bool>& isVisited, vector<int>& result, vector<vector<int>>& graph)
{
    isVisited[u] = true;
    result[u] *= p;
    
    for (int v : graph[u])
    {
        if (isVisited[v])
            continue;

        DFS(v, p, isVisited, result, graph);
    }
}

int main()
{
    FastIO;

    int n;
    cin>> n;

    vector<vector<int>> graph(n);
    vector<Ratio> ratio(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, p, q;
        cin>>a >> b >> p >> q;

        ratio[i] = { a,b,p,q };
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> result(n, 1);
    for (int i = 0; i < n - 1; i++)
    {
        vector<bool> isVisited(n, false);

        Ratio& r = ratio[i];
        
        isVisited[r.b] = true;
        DFS(r.a, r.p, isVisited, result, graph);

        isVisited[r.b] = false;
        DFS(r.b, r.q, isVisited, result, graph);
    }

    int gcd = ArrayGCD(result);
    for (int i = 0; i < n; i++)
    {
        result[i] /= gcd;
        cout << result[i] << ' ';
    }
    cout << '\n';
}