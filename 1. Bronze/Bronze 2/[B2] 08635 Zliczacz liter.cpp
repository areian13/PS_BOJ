#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    cin.ignore();
    array<array<int, 26>, 2> result = { 0, };
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        for (char c : s)
        {
            if (c == ' ')
                continue;

            result[!!(c & 32)][(c | 32) - 'a']++;
        }
    }

    for (int i = 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (result[i][j] != 0)
                cout << (char)(j + 'A' + 32 * i) << ' ' << result[i][j] << '\n';
        }
    }
}