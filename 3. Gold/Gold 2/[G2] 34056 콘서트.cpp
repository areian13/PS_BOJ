#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int q, c;
        cin >> q >> c;
        c--;

        if (q == 1)
        {
            int x;
            cin >> x;

            int rx = x;
            for (int i = c + 1; i < n && rx > 0; i++)
            {
                long long p = min(d[i], 1LL * rx);
                d[i] += p;
                rx -= p;
            }
            for (int i = c; i >= 0 && x > 0; i--)
            {
                long long p = min(d[i], 1LL * x);
                d[i] += p;
                x -= p;
            }
        }
        else
            cout << d[c] << '\n';
    }
}