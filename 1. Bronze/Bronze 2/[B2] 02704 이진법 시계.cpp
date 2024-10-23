#include <iostream>
#include <cstdio>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        array<int, 3> t;
        scanf("%02d:%02d:%02d", &t[0], &t[1], &t[2]);

        string result(3 * 6, '\0');
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                result[i * 6 + 5 - j] = t[i] % 2 + '0';
                t[i] /= 2;
            }
        }

        for (int j = 0; j < 6; j++)
        {
            for (int i = 0; i < 3; i++)
                cout << result[i * 6 + j];
        }
        cout << ' ' << result << '\n';
    }
}