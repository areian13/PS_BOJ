#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    bool k;
    cin >> n >> k;

    if (n > 5)
        cout << "Love is open door" << '\n';
    else
    {
        for (int i = 2; i <= n; i++)
            cout << (i + k + 1) % 2 << '\n';
    }
}