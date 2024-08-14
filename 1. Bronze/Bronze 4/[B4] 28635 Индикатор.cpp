#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, a, b;
    cin >> m >> a >> b;

    int result = (m + b - a) % m;
    cout << result << '\n';
}