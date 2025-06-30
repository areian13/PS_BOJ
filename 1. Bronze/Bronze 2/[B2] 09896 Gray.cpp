#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Graying(string& s)
{
    int n = s.size();

    string result = "";
    result += s[0];
    for (int i = 1; i < n; i++)
        result += (s[i - 1] == s[i] ? '0' : '1');
    return result;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = Graying(s);
    cout << result << '\n';
}