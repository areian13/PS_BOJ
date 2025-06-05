#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, t;
    cin >> a >> b >> c >> t;

    int result = a + (max(t - 30, 0) + b - 1) / b * c;
    cout << result << '\n';
}