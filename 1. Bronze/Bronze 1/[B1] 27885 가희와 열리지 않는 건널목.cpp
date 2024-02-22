#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SEC (24 * 60 * 60)

int main()
{
    FastIO;

    array<bool, SEC> train;
    fill(train.begin(), train.end(), true);

    int c, h;
    scanf("%d %d", &c, &h);

    for (int i = 0; i < c + h; i++)
    {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);

        int sec = hh * 3600 + mm * 60 + ss;
        for (int j = sec; j < sec + 40; j++)
            train[j] = false;
    }
    int result = 0;
    for (int i = 0; i < SEC; i++)
        result += train[i];
    cout << result << '\n';
}