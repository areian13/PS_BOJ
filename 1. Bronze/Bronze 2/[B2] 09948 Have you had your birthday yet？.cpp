#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, int> month;
    month["January"] = 0;
    month["February"] = 1;
    month["March"] = 2;
    month["April"] = 3;
    month["May"] = 4;
    month["June"] = 5;
    month["July"] = 6;
    month["August"] = 7;
    month["September"] = 8;
    month["October"] = 9;
    month["November"] = 10;
    month["December"] = 11;

    while (true)
    {
        int n;
        string m;
        cin >> n >> m;

        if (n == 0 && m == "#")
            break;

        int result = month[m] * 31 + n;
        int a4 = month["August"] * 31 + 4;
        int f29 = month["February"] * 31 + 29;
        if (result == f29)
            cout << "Unlucky" << '\n';
        else if (result < a4)
            cout << "Yes" << '\n';
        else if (result > a4)
            cout << "No" << '\n';
        else
            cout << "Happy birthday" << '\n';
    }
}