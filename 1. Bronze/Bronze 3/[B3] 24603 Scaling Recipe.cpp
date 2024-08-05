#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x, y;
    cin >> n >> x >> y;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        int result = a * y / x;
        cout << result << '\n';
    }
}