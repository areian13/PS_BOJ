#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BS(int g, int k)
{
    int start = 0;
    int end = INT_MAX;

    double lValue = (double)(g - 100) / (100 * k - 90);

    int result;
    while (start <= end)
    {
        int n = (start + end) / 2;
        if (lValue <= n)
        {
            result = n;
            end = n - 1;
        }
        else
            start = n + 1;
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int g, k;
        cin >> g >> k;

        int result = BS(g, k);
        cout << result << '\n';
    }
}