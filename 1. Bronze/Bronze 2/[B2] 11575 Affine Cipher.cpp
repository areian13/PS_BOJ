#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;

        for (char& c : s)
            c = ((c - 'A') * a + b) % 26 + 'A';
        cout << s << '\n';
    }
}