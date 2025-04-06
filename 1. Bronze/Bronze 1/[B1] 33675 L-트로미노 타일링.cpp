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
        int n;
        cin >> n;

        long long result = (n % 2 == 1 ? 0 : 1LL << (n / 2));
        cout << result << '\n';
    }
}