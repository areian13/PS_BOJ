#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        pair<int, int> result = { 1, INT_MAX };
        double ce = (double)result.first / result.second;
        for (int i = 0; i < n; i++)
        {
            int w, c;
            cin >> w >> c;

            double nce = (double)w / c;
            if (nce > ce || nce == ce && c < result.second)
            {
                result = { w,c };
                ce = nce;
            }
        }

        cout << result.second << '\n';
    }
}