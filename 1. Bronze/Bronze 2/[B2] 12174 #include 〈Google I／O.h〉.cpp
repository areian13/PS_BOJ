#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int b;
        cin >> b;

        string result = "";
        for (int i = 0; i < b; i++)
        {
            char c = 0;
            for (int j = 0; j < 8; j++)
            {
                char bit;
                cin >> bit;

                c <<= 1;
                c += (bit == 'I');
            }
            result += c;
        }

        printf("Case #%d: %s\n", tc, result.c_str());
    }
}