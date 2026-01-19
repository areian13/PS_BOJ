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

        n = (n - 1) % 28 + 1;
        if (n > 15)
            n = 30 - n;

        for (int i = 3; i >= 0; i--)
        {
            if (n & (1 << i)) cout << "µþ±â";
            else cout << 'V';
        }
        cout << '\n';
    }
}