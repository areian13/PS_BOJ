#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h, m, s;
    cin >> h >> m >> s;

    int result = (3600 * h + 60 * m + s + 1) % (24 * 3600);
    printf("%02d:%02d:%02d\n", result / 60 / 60, result / 60 % 60, result % 60);
}