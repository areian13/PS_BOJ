#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Circle(string& s, int d)
{
    int n = s.size();
    string result = "";
    for (int i = 0; i < n; i++)
        result += s[(i + d) % n];
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        int n = s.size();
        string result = s;
        for (int i = 1; i < n; i++)
            result = min(result, Circle(s, i));
        cout << result << '\n';
    }
}