#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> c(n);
        long long cSum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            cSum += c[i];
        }
        double cAvg = (double)cSum / n;

        long long eSum = 0;
        for (int i = 0; i < m; i++)
        {
            int e;
            cin >> e;
            eSum += e;
        }
        double eAvg = (double)eSum / m;

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            double cNewAvg = (double)(cSum - c[i]) / (n - 1);
            double eNewAvg = (double)(eSum + c[i]) / (m + 1);

            result += (cNewAvg > cAvg && eNewAvg > eAvg);
        }
        cout << result << '\n';
    }
}