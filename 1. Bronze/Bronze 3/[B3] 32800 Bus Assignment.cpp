#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        cur += b - a;
        result = max(result, cur);
    }
    cout << result << '\n';
}