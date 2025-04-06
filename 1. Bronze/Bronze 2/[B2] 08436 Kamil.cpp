#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<bool, 26> canWrong = { false, };
    canWrong['T' - 'A'] = true;
    canWrong['D' - 'A'] = true;
    canWrong['L' - 'A'] = true;
    canWrong['F' - 'A'] = true;

    string s;
    cin >> s;

    int result = 1;
    for (char c : s)
        result <<= canWrong[c - 'A'];
    cout << result << '\n';
}