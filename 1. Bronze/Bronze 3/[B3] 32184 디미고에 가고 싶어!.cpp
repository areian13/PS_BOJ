#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = (b / 2 * 2 - (a / 2 * 2 + 1) + 1) / 2 + (a % 2 == 0) + (b % 2 == 1);
    cout << result << '\n';
}