#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 8 * (n - 1);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        result += t;
    }
    cout << result / 24 << ' ' << result % 24 << '\n';
}