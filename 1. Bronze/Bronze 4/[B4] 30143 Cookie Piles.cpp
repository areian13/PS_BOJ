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
        int n, a, d;
        cin >> n >> a >> d;

        int result = a * n + (n - 1) * d * n / 2;
        cout << result << '\n';
    }
}