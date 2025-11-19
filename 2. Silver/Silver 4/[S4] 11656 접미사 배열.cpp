#include <iostream>
#include <string>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    set<string> result;
    for (int i = 0; i < n; i++)
        result.insert(s.substr(i));

    for (const string& suf : result)
        cout << suf << '\n';
}