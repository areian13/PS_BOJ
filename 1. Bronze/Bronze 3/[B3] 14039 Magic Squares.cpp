#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMagic(vector<vector<int>>& s)
{
    int n = s.size();

    int value = accumulate(s[0].begin(), s[0].end(), 0);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += s[i][j];
        if (sum != value)
            return false;
    }

    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += s[i][j];
        if (sum != value)
            return false;
    }

    return true;
}

int main()
{
    FastIO;

    int n = 4;

    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    }

    string result = IsMagic(s) ? "magic" : "not magic";
    cout << result << '\n';
}