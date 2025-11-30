#include <iostream>
#include <vector>

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

    int result = 0, maxH = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxH < h[i])
        {
            maxH = h[i];
            result++;
        }
    }
    cout << result << '\n';
}