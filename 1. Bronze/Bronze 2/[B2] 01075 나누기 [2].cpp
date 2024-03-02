#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, f;
    cin >> n >> f;

    int result = n / 100 * 100;
    while (result % f != 0)
        result++;
    result %= 100;

    printf("%02d", result);
}