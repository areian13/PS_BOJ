#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<string, 9> heart =
    {
        " @@@   @@@ ",
        "@   @ @   @",
        "@    @    @",
        "@         @",
        " @       @ ",
        "  @     @  ",
        "   @   @   ",
        "    @ @    ",
        "     @     ",
    };

    int n;
    cin >> n;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < n; j++)
            cout << heart[i] << ' ';
        cout << '\n';
    }
}