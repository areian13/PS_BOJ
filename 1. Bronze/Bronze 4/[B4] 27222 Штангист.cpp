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

    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        result += max(y - x, 0) * w[i];
    }
    cout << result << '\n';
}