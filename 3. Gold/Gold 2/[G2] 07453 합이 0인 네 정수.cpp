#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long ZeroPair(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d)
{
    int n = a.size();

    vector<int> ab(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            ab[i * n + j] = a[i] + b[j];
    }
    sort(ab.begin(), ab.end());

    vector<int> cd(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cd[i * n + j] = c[i] + d[j];
    }
    sort(cd.begin(), cd.end());

    long long result = 0;
    int i = 0, j = n * n - 1;
    while (i < n * n && j >= 0)
    {
        if (ab[i] + cd[j] < 0)
            i++;
        else if (ab[i] + cd[j] > 0)
            j--;
        else
        {
            int lcnt = 1;
            while (i < n * n - 1 && ab[i] == ab[i + 1])
            {
                lcnt++;
                i++;
            }
            int rcnt = 1;
            while (j >= 1 && cd[j] == cd[j - 1])
            {
                rcnt++;
                j--;
            }

            result += (long long)lcnt * rcnt;
            i++, j++;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    long long result = ZeroPair(a, b, c, d);
    cout << result << '\n';
}