#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = (n + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;

        result -= (r == 1);
    }
    result = max(result, 0);
    cout << result << '\n';
}