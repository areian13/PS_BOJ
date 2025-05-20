#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = 24 * 60 * m / n;
    printf("%02d:%02d\n", result / 60, result % 60);
}