#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    char m;
    int n;
    cin >> m >> n;

    array<bool, 26> isUsed = { false, };
    isUsed[m - 'A'] = true;
    for (int i = 0; i < n; i++)
    {
        char x, y;
        cin >> x >> y;

        if (y == m)
        {
            isUsed[x - 'A'] = true;
            m = x;
        }
    }
    int result = 0;
    for (char c = 0; c < 26; c++)
        result += isUsed[c];
    cout << m << '\n';
    cout << result << '\n';
}