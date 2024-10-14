#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m - 1; i++)
        cout << i << ' ' << m - 1 << '\n';;
    for (int i = m - 1; i < n - 1; i++)
        cout << i << ' ' << i + 1 << '\n';
}