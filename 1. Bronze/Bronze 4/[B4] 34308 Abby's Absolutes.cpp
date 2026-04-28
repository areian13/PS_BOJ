#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;

        int result = (a - 1 <= n - a ? 1 : n);
        cout << result << ' ';
    }
    cout << '\n';
}