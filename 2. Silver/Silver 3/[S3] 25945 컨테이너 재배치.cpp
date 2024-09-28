#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> height(n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
        m += height[i];
    }
    sort(height.begin(), height.end());
    int y = m / n;

    int result = 0;
    int over = 0;
    for (int i = 0; i < n; i++)
    {
        if (height[i] < y)
            result += y - height[i];
        else if (height[i] > y + 1)
            over += height[i] - (y + 1);
    }
    result += max(over - result, 0);
    cout << result << '\n';
}