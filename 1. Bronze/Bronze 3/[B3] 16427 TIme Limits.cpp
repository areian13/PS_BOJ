#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, s;
    cin >> n >> s;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        result = max(result, (t * s + 999) / 1000);
    }
    cout << result << '\n';
}