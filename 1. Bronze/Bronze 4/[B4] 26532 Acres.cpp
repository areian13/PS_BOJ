#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = n * m / (5 * 4840) + (n * m % (5 * 4840) != 0);
    cout << result << '\n';
}