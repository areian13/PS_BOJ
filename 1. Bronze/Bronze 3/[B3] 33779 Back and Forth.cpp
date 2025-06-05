#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPalin(string& s)
{
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    bool result = IsPalin(s);
    if (result == true)
        cout << "beep" << '\n';
    else
        cout << "boop" << '\n';
}