#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Base26ToDec(string num)
{
    int d = num.size();

    int result = 0;
    int power = 1;
    for (int i = d - 1; i >= 0; i--)
    {
        result += (num[i] - 'A') * power;
        power *= 26;
    }
    return result;
}

bool IsNice(string& s)
{
    return abs(Base26ToDec(s.substr(0, 3)) - stoi(s.substr(4))) <= 100;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;

        string result = (IsNice(s) ? "nice" : "not nice");
        cout << result << '\n';
    }
}