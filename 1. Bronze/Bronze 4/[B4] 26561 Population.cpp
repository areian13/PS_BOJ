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
        int p, t;
        cin >> p >> t;

        int result = p - t / 7 + t / 4;
        cout << result << '\n';
    }
}