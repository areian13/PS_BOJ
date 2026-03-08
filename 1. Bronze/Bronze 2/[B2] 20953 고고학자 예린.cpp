#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int a, b;
        cin >> a >> b;

        long long t = a + b;
        long long result = t * t * (t - 1) / 2;
        cout << result << '\n';
    }
}