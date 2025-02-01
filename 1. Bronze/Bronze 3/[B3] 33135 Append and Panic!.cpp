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

    array<bool, 26> has = { false, };
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (has[s[i] - 'A'])
        {
            cout << i + 1 << '\n';
            break;
        }
        has[s[i] - 'A'] = true;
    }
}