#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 26> r = { 0, };
    r['I' - 'A'] = 1;
    r['V' - 'A'] = 5;
    r['X' - 'A'] = 10;
    r['L' - 'A'] = 50;
    r['C' - 'A'] = 100;
    r['D' - 'A'] = 500;
    r['M' - 'A'] = 1'000;

    string s;
    cin >> s;

    int n = s.size();
    int result = 0;
    for (int i = 0; i < n; i += 2)
    {
        int value = (s[i] - '0') * r[s[i + 1] - 'A'];
        if (i < n - 3 && r[s[i + 1] - 'A'] < r[s[i + 3] - 'A'])
            value *= -1;
        result += value;
    }
    cout << result << '\n';
}