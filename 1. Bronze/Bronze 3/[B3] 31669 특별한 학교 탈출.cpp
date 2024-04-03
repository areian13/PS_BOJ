#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int EscapeTime(vector<vector<char>>& schedule)
{
    int n = schedule.size();
    int m = schedule[0].size();

    for (int j = 0; j < m; j++)
    {
        bool canEscape = true;
        for (int i = 0; i < n; i++)
            canEscape &= (schedule[i][j] == 'X');

        if (canEscape)
            return j + 1;
    }
    return -1;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> schedule(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> schedule[i][j];
    }

    int escapeTime = EscapeTime(schedule);
    string result = (escapeTime != -1 ? to_string(escapeTime) : "ESCAPE FAILED");
    cout << result << '\n';
}