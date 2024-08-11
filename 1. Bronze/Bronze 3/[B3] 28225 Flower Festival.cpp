#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, f;
    cin >> n >> f;

    int result = 0;
    double minTime = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int x, v;
        cin >> x >> v;

        double time = (double)(f - x) / v;
        if (minTime > time)
        {
            minTime = time;
            result = i;
        }
    }
    cout << result << '\n';
}