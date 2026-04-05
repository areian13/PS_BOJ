#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        sum += d;
    }

    bool result = (~sum & 1 || n > 1);
    cout << (result ? "YES" : "NO") << '\n';
}