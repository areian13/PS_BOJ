#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Query(string s)
{
    string result = "";

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (s[i] == s[i + cnt])
            cnt++;
        result += to_string(cnt) + s[i];
        i += cnt - 1;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = s;
    for (int i = 0; i < n; i++)
        result = Query(result);
    cout << result << '\n';
}