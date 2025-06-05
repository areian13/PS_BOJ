#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x;
    cin >> x;

    int result = x / 2 + 3 * (x % 2);
    cout << result << '\n';
}