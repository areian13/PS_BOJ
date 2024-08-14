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
        int a, b, x;
        cin >> a >> b >> x;

        int result = a * (x - 1) + b;
        cout << result << '\n';
    }
}