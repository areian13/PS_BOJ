#include <iostream>
#include <cstdio>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Winner(char a, char b)
{
    if (a == b)
        return 2;
    return !(a == 'R' && b == 'S' || a == 'S' && b == 'P' || a == 'P' && b == 'R');
}

int main()
{
    FastIO;

    while (true)
    {
        string p1, p2;
        cin >> p1 >> p2;

        if (p1 == "E" && p2 == "E")
            break;

        int n = p1.size();
        array<int, 3> result = { 0,0,0 };
        for (int i = 0; i < n; i++)
            result[Winner(p1[i], p2[i])]++;

        printf("P1: %d\nP2: %d\n", result[0], result[1]);
    }
}