#include <iostream>
#include <vector>
#include <map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsNum(string& s)
{
    for (char c : s)
    {
        if (!('0' <= c && c <= '9'))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<string> numToName(n);
    map<string, int> nameToNum;
    for (int i = 0; i < n; i++)
    {
        cin >> numToName[i];
        nameToNum[numToName[i]] = i;
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        if (IsNum(s))
            cout << numToName[stoi(s) - 1] << '\n';
        else
            cout << nameToNum[s] + 1 << '\n';
    }
}