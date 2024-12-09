#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double GetRate(string& name, unordered_map<string, double>& rates,
    unordered_map<string, vector<string>>& graph)
{
    if (rates[name] != -1)
        return rates[name];
    if (graph[name].empty())
        return rates[name] = 0;

    double dad = GetRate(graph[name][0], rates, graph);
    double mom = GetRate(graph[name][1], rates, graph);
    return rates[name] = dad / 2 + mom / 2;
}

int main()
{
    FastIO;

    int n, m;
    string root;
    cin >> n >> m >> root;

    unordered_map<string, vector<string>> graph;
    unordered_map<string, double> rates;
    for (int i = 0; i < n; i++)
    {
        string u, v1, v2;
        cin >> u >> v1 >> v2;

        graph[u].push_back(v1);
        graph[u].push_back(v2);
        rates[u] = rates[v1] = rates[v2] = -1;
    }

    rates[root] = 1;

    double maxRate = 0;
    string result = "";
    for (int i = 0; i < m; i++)
    {
        string name;
        cin >> name;

        double rate = GetRate(name, rates, graph);
        if (maxRate < rate)
        {
            maxRate = rate;
            result = name;
        }
    }
    cout << result << '\n';
}