#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        result = min(result, b / a);
    }
    cout << result << '\n';
}