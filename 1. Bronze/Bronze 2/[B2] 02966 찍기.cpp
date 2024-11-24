#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    const array<const string, 3> patterns = { "ABC","BABC","CCAABB" };
    const array<const string, 3> names = { "Adrian","Bruno","Goran" };

    int n;
    string s;
    cin >> n >> s;

    array<int, 3> scores;
    int maxScore = 0;
    for (int i = 0; i < 3; i++)
    {
        int score = 0;
        for (int j = 0; j < n; j++)
            score += (s[j] == patterns[i][j % patterns[i].size()]);

        scores[i] = score;
        maxScore = max(maxScore, score);
    }

    cout << maxScore << '\n';
    for (int i = 0; i < 3; i++)
    {
        if (scores[i] == maxScore)
            cout << names[i] << '\n';
    }
}