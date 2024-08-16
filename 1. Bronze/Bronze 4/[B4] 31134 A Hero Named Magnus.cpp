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
        int x;
        cin >> x;

        long long result = x * 2LL - 1;
        cout << result << '\n';
    }
}