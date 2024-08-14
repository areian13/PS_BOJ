#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, int> dy, dx;
    dy['N'] = +1;
    dx['N'] = 0;
    dy['S'] = -1;
    dx['S'] = 0;
    dy['W'] = 0;
    dx['W'] = -1;
    dy['E'] = 0;
    dx['E'] = +1;

    int n;
    string s;
    cin >> n >> s;

    int y = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        y += dy[s[i]];
        x += dx[s[i]];
    }

    int result = abs(y) + abs(x);
    cout << result << '\n';
}