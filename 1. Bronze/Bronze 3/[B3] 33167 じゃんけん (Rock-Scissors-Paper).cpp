#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Num(char c)
{
    if (c == 'S')
        return 0;
    if (c == 'R')
        return 1;
    return 2;
}

int main()
{
    FastIO;

    int n;
    string s, t;
    cin >> n >> s >> t;

    array<int, 3> result = { 0,0,0 };
    for (int i = 0; i < n; i++)
        result[(Num(s[i]) - Num(t[i]) + 3) % 3]++;

    cout << result[1] << ' ' << result[2] << '\n';
}