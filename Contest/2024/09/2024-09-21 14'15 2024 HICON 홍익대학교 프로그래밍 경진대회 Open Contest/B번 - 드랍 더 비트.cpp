#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    int result = ((1 << n) - 1) - ((1 << abs(n - (a + b))) - 1);
    cout << result << '\n';
}