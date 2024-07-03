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
        int k, n;
        cin >> k >> n;

        int result = n * (n + 1) / 2 + n;
        cout << k << ' ' << result << '\n';
    }
}