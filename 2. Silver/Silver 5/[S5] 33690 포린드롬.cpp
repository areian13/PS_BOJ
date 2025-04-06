#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void NextS(string& s)
{
    int n = s.size();
    if (s[0] == '9')
        s = string(n + 1, '1');
    else
    {
        for (int i = 0; i < n; i++)
            s[i] = s[i] + 1;
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    string s = "0";
    int result = 0;
    while (stoi(s) <= n)
    {
        result++;
        NextS(s);
    }
    cout << result << '\n';
}