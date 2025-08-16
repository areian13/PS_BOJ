#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, c;
    cin >> n >> c;

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int p, d, v;
        cin >> p >> d >> v;

        result = min(result, p + d + v * c);
    }
    cout << result << '\n';
}