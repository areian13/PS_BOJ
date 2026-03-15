#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        result = (result * max(a, 1)) % m;
    }
    result %= m;

    cout << result << '\n';
}