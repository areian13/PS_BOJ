#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const string ascii = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        string s;
        cin >> s;

        reverse(s.begin(), s.end());
        for (char& c : s)
            c = ascii[(ascii.find(c) + n) % ascii.size()];
        cout << s << '\n';
    }
}