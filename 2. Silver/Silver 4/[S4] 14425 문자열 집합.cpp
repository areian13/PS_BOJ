#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    unordered_map<string, bool> isS;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        isS[s] = true;
    }

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        string p;
        cin >> p;

        result += isS[p];
    }
    cout << result << '\n';
}