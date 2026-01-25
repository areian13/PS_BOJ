#include <iostream>
#include <cstdio>
#include <array>
#include <string>
#include <cmath>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<string, 7> week = {
    "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"
};

int Ovewrap(array<int, 4>& t)
{
    auto [a, b, n, m] = t;

    if (abs(a - b) % gcd(n, m) != 0)
        return -1;

    while (true)
    {
        if (a == b) return a;
        if (a < b) a += n;
        else b += m;
    }
    return -1;
}

int main()
{
    FastIO;

    array<int, 4> t;
    for (int i = 0; i < 4; i++)
    {
        int h, m;
        scanf("%02d:%02d", &h, &m);
        t[i] = h * 60 + m;
    }

    int result = Ovewrap(t);
    if (result == -1)
        printf("Never\n");
    else
    {
        printf("%s\n", week[result / (24 * 60) % 7].c_str());
        printf("%02d:%02d\n", result % (24 * 60) / 60, result % 60);
    }
}