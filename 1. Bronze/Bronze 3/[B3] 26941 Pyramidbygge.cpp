#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Pyramid(int n)
{
    return n * (2 * n - 1) * (2 * n + 1) / 3;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    while (Pyramid(result + 1) <= n)
        result++;
    cout << result << '\n';
}