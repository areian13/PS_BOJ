#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsInANJ(vector<string>& players)
{
    for (string& player : players)
    {
        if (player == "anj")
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> players(n);
    for (int i = 0; i < n; i++)
        cin >> players[i];

    string result = (IsInANJ(players) ? "构具;" : "构具?");
    cout << result << '\n';
}