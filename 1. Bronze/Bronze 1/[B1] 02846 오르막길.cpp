#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> high(n);
    for (int i = 0; i < n; i++)
        cin >> high[i];

    int minHigh = high[0];
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        if (high[i] > high[i - 1])
            result = max(result, high[i] - minHigh);
        else
            minHigh = high[i];
    }
    cout << result << '\n';
}