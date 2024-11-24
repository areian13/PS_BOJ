#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanLight(int l, int n, vector<int>& x)
{
    int cur = 0;
    for (int p : x)
    {
        if (cur < p - l)
            return false;
        cur = p + l;
    }
    return cur > n - 1;
}

int MinHeight(int n, vector<int>& x)
{
    int start = 1, end = n;

    int result = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (!CanLight(mid, n, x))
            start = mid + 1;
        else
        {
            result = min(result, mid);
            end = mid - 1;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for (int i = 0; i < m; i++)
        cin >> x[i];

    int result = MinHeight(n, x);
    cout << result << '\n';
}