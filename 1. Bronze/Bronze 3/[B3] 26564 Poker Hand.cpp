#include <iostream>
#include <array>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Numbering(string& card)
{
    char c = card[0];
    if (c == 'A')
        return 1;
    if (c == 'T')
        return 10;
    if (c == 'J')
        return 11;
    if (c == 'Q')
        return 12;
    if (c == 'K')
        return 13;
    return c - '0';
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        array<int, 13> cnt = { 0, };
        for (int i = 0; i < 5; i++)
        {
            string card;
            cin >> card;

            cnt[Numbering(card) - 1]++;
        }

        int result = 0;
        for (int i = 0; i < 13; i++)
            result = max(result, cnt[i]);
        cout << result << '\n';
    }
}