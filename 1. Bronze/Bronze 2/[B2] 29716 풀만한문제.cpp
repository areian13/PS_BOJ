#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Jabcho(string& s)
{
    int result = 0;
    for (char c : s)
    {
        if (c == ' ') result++;
        else if ('A' <= c && c <= 'Z') result += 4;
        else result += 2;
    }
    return result;
}

int main()
{
    FastIO;

    int j, n;
    cin >> j >> n;
    cin.ignore();

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        result += (Jabcho(s) <= j);
    }
    cout << result << '\n';
}