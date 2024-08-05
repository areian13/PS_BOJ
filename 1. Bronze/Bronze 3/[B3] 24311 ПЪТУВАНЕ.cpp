#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t1, t2, t3, t4, t5, br, t6;
    cin >> t1 >> t2 >> t3 >> t4 >> t5 >> br >> t6;

    int result = 60 * t1 + t2 - t3 - (60 * t4 + t5) - (br + 1) * t6 - 10;
    printf("%02d %02d\n", result / 60, result % 60);
}