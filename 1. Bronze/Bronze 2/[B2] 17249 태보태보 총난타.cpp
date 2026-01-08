#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    array<int, 2> result = { 0,0 };
    bool flag = false;
    for (char c : s)
    {
        result[flag] += (c == '@');
        flag |= (c == '0');
    }
    cout << result[0] << ' ' << result[1] << '\n';
}