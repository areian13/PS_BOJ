#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Yes(int j, vector<vector<char>>& schedule)
{
    int n = schedule.size();

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (schedule[i][j] == 'Y');
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int m = 5;
    vector<vector<char>> schedule(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> schedule[i][j];
    }

    int maxYes = 0;
    for (int i = 0; i < m; i++)
        maxYes = max(maxYes, Yes(i, schedule));

    string result = "";
    for (int i = 0; i < m; i++)
    {
        if (Yes(i, schedule) == maxYes)
            result += to_string(i + 1) + ',';
    }
    result.pop_back();
    cout << result << '\n';
}