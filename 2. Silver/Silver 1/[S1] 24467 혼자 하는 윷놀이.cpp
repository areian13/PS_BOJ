#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

vector<vector<int>> graph(33);
void BuildGraph()
{
    for (int i = 0; i < 19; i++)
        graph[i].push_back(i + 1);

    graph[19].push_back(32);

    graph[4].push_back(20);
    graph[20].push_back(21);
    graph[21].push_back(22);
    graph[22].push_back(23);
    graph[23].push_back(24);
    graph[24].push_back(25);
    graph[25].push_back(15);

    graph[22].push_back(29);

    graph[9].push_back(26);
    graph[26].push_back(27);
    graph[27].push_back(28);
    graph[28].push_back(29);
    graph[29].push_back(30);
    graph[30].push_back(31);
    graph[31].push_back(32);
}

int Jump(string& s)
{
    int sum = 0;
    for (char c : s)
        sum += c - '0';

    if (sum == 4) return 5;
    return 4 - sum;
}

int Turn(vector<int>& jump)
{
    int n = jump.size();
    int u = 0, result = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || jump[i - 1] < 4)
            result++;

        for (int j = 0; j < jump[i] - 1; j++)
        {
            u = graph[u][0];
            if (u == 32)
                return result;
        }
        u = graph[u].back();

        if (u == 32)
            return result + 1;
    }
    return 11;
}

int main()
{
    FastIO;

    BuildGraph();

    vector<int> jump;
    while (true)
    {
        string s;
        cin >> s;

        if (cin.eof())
            break;

        jump.push_back(Jump(s));
    }

    int result = Turn(jump);
    cout << (result <= 10 ? "WIN" : "LOSE") << '\n';
}