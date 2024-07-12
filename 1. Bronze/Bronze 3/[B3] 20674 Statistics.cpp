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

    int minValue = INT_MAX;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        minValue = min(minValue, value);
        result += max(value - minValue, 0);
    }
    cout << result << '\n';
}