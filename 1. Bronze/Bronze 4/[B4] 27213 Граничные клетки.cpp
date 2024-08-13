#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    int result = (m != 1 && n != 1) ? (n + m) * 2 - 4 : n * m;
    cout << result << '\n';
}