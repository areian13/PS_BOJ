#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ctod(char c)
{
    if (c == 'A')
        return 0;
    if (c == 'T')
        return 9;
    if (c == 'J')
        return 10;
    if (c == 'Q')
        return 11;
    if (c == 'K')
        return 12;
    return c - '1';
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        vector<vector<string>> decks(13, vector<string>(4));
        decks[12][3] = s;

        for (int i = 3; i >= 0; i--)
        {
            for (int j = 12; j >= 0; j--)
            {
                if (i == 3 && j == 12)
                    continue;
                cin >> decks[j][i];
            }
        }

        int curr = 12;
        int result = 0;
        string last = "";
        while (!decks[curr].empty())
        {
            result++;

            last = decks[curr].back();
            decks[curr].pop_back();
            curr = ctod(last[0]);
        }

        printf("%02d,%s\n", result, last.c_str());
    }
}