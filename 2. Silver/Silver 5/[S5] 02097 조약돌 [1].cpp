#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int k = sqrt(max(n - 1, 1));
    int result = k * 4;

    if (n - k * k <= k && n > 4)
        result -= 2;
    cout << result << '\n';
}