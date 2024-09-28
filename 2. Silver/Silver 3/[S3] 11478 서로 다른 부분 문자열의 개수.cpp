#include <iostream>
#include <string>
#include <unordered_set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    unordered_set<string> subStringSet;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; i + j <= n; j++)
            subStringSet.insert(s.substr(i, j));
    }

    int result = subStringSet.size();
    cout << result << '\n';
}