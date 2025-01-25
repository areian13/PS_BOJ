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

    vector<string> ingredients(n);
    for (int i = 0; i < n; i++)
        cin >> ingredients[i];

    unordered_map<string, bool> has;
    for (int i = 0; i < n - 1; i++)
    {
        string s;
        cin >> s;
        has[s] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (!has[ingredients[i]])
            cout << ingredients[i] << ' ';
    }
    cout << '\n';
}