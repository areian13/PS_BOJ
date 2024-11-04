#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c, k;
    cin >> c >> k;

    int b = pow(10, k);
    int result = (int)((double)c / b + 0.5) * b;
    cout << result << '\n';
}