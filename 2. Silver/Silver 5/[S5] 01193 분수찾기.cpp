#include <iostream>
#include <cstdio>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x;
    cin >> x;

    array<int, 2> result = { 1,1 };
    bool dir = true;
    int n = 1;
    for (int i = 0; i < x - 1; i++)
    {
        if (result[dir] == n)
        {
            result[dir]++;
            n++;
            dir = !dir;
        }
        else
        {
            result[dir]++;
            result[!dir]--;
        }
    }
    printf("%d/%d\n", result[0], result[1]);
}