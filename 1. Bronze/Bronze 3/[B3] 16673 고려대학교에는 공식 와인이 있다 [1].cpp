#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c, k, p;
    cin >> c >> k >> p;

    int result = 0;
    for (int n = 1; n <= c; n++)
        result += k * n + p * n * n;
    cout << result << '\n';
}