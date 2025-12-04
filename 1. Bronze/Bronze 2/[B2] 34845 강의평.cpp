#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, x;
    cin >> n >> x;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }

    int result = 0;
    while ((sum + 100 * result) < x * (n + result))
        result++;
    cout << result << '\n';
}