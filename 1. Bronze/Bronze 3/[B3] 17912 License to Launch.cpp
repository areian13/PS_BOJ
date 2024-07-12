#include <iostream>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int minTresh = INT_MAX;
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        int tresh;
        cin >> tresh;

        if (tresh < minTresh)
        {
            minTresh = tresh;
            result = i;
        }
    }
    cout << result << '\n';
}