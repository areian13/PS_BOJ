#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, t;
    cin >> a >> t;

    int result = max(10 + 2 * (25 - a + t), 0);
    cout << result << '\n';
}