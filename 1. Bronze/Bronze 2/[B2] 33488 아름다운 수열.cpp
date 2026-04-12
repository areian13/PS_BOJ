#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++)
    {
        int n;
        cin >> n;

        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << '\n';
    }
}