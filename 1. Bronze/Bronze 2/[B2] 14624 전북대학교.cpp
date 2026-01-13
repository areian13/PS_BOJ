#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    if (~n & 1) cout << "I LOVE CBNU" << '\n';
    else
    {
        cout << string(n, '*') << '\n';
        for (int i = 0; i < n / 2 + 1; i++)
        {
            string t(n / 2 + 1 + i, ' ');
            t.back() = '*';
            t[n / 2 - i] = '*';
            cout << t << '\n';
        }
    }
}