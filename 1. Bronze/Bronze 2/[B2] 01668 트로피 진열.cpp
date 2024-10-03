#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    array<int, 2> result = { 0,0 };
    array<int, 2> maxH = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        result[0] += (h[i] > maxH[0]);
        maxH[0] = max(maxH[0], h[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        result[1] += (h[i] > maxH[1]);
        maxH[1] = max(maxH[1], h[i]);
    }

    cout << result[0] << '\n';
    cout << result[1] << '\n';
}