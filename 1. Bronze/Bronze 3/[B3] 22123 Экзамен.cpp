#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_SEC (24 * 60 * 60)

string Igor(int h1, int m1, int s1, int h2, int m2, int s2, int k)
{
    int gapSec = (MAX_SEC + 60 * 60 * h2 + 60 * m2 + s2 - (60 * 60 * h1 + 60 * m1 + s1) - 1) % MAX_SEC + 1;
    if (60 * k <= gapSec)
        return "Perfect";
    if (60 * k <= gapSec + 60 * 60)
        return "Test";
    return "Fail";
}

int main()
{
    FastIO;

    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        int h1, m1, s1, h2, m2, s2, k;
        scanf("%d:%d:%d %d:%d:%d %d", &h1, &m1, &s1, &h2, &m2, &s2, &k);

        string result = Igor(h1, m1, s1, h2, m2, s2, k);
        cout << result << '\n';
    }
}