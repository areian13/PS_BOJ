#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string EOParity(string s)
{
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
        cnt += (s[i] - '0');

    s[n - 1] = (cnt % 2 == 0) ^ (s.back() == 'o') ? '0' : '1';
    return s;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        string result = EOParity(s);
        cout << result << '\n';
    }
}