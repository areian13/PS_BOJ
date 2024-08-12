#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, p;
        cin >> n >> p;

        int result = n * p - (n - 1) * 2;
        cout << n << ' ' << p << '\n';
        cout << result << '\n';
    }
}