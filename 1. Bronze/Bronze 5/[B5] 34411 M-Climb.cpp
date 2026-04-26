#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int m, n, y;
    cin >> m >> n >> y;

    int result = m * n;
    cout << result << '\n';
}