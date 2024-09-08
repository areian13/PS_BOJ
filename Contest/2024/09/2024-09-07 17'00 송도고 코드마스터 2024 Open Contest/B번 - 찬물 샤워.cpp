#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k, t;
    cin >> n >> k >> t;

    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int dt = abs(t - k);
        t = t + d[i] + (t > k ? -dt : +dt);

        if (i != 0)
            result += dt;
    }
    result += abs(t - k);

    cout << result << '\n';
}