#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    unordered_map<string, vector<string>> jukebox;
    for (int i = 0; i < n; i++)
    {
        int t;
        string s;
        cin >> t >> s;

        string sheet = "";
        for (int i = 0; i < 7; i++)
        {
            char a;
            cin >> a;
            sheet += a;
        }
        jukebox[sheet.substr(0, 3)].push_back(s);
    }

    while (m--)
    {
        string sheet = "";
        for (int i = 0; i < 3; i++)
        {
            char a;
            cin >> a;
            sheet += a;
        }

        string result = (jukebox[sheet].size() == 1 ? jukebox[sheet][0] : (jukebox[sheet].empty() ? "!" : "?"));
        cout << result << '\n';
    }
}