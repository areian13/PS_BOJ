#include <iostream>
#include <vector>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, QC;
    cin >> n >> QC;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int qc = 1; qc <= QC; qc++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;

            long long result = accumulate(v.begin() + a, v.begin() + b + 1, 0LL);
            cout << result << '\n';
            swap(v[a], v[b]);
        }
        else
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;

            long long result = accumulate(v.begin() + a, v.begin() + b + 1, 0LL)
                - accumulate(v.begin() + c, v.begin() + d + 1, 0LL);
            cout << result << '\n';
        }
    }
}