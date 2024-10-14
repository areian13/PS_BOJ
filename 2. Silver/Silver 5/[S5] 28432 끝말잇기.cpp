#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int qIdx = -1;
    vector<string> list(n);
    unordered_map<string, bool> isAppeared;
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
        isAppeared[list[i]] = true;
        if (list[i] == "?")
            qIdx = i;
    }

    int m;
    cin >> m;

    string result = "";
    for (int i = 0; i < m; i++)
    {
        string word;
        cin >> word;

        if (n == 1)
        {
            result = word;
            break;
        }

        if (!isAppeared[word])
        {
            if (qIdx == 0 && list[qIdx + 1][0] == word[word.size() - 1])
                result = word;
            else if (qIdx == n - 1 && list[qIdx - 1][list[qIdx - 1].size() - 1] == word[0])
                result = word;
            else if (qIdx != 0 && qIdx != n - 1 && list[qIdx + 1][0] == word[word.size() - 1] && list[qIdx - 1][list[qIdx - 1].size() - 1] == word[0])
                result = word;
        }
    }
    cout << result << '\n';
}