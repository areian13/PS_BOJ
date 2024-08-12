#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ';
        if (i % 6 == 0 || i == n)
            cout << "Go!" << ' ';
    }
    cout << '\n';
}