#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, t;
    cin >> n >> t;

    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        sum += a;
        result += (sum <= t);
    }
    cout << result << '\n';
}