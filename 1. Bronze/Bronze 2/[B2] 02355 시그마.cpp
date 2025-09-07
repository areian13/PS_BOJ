#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    long long result = (a + b) * (b - a + 1) / 2;
    cout << result << '\n';
}