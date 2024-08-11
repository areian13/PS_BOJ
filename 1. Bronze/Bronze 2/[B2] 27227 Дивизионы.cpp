#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool inDiv(int t, string& d)
{
    for (char c : d)
    {
        if (c - '0' == t)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int r;
    string d;
    cin >> r >> d;

    int t = 2;
    if (r <= 1600)
        t = 3;
    else if (r > 1900)
        t = 1;

    if (inDiv(t, d))
        cout << t << '\n';
    else
    {
        for (char c : d)
            cout << c << (c - '0' > t ? "*" : "") << '\n';
    }
}