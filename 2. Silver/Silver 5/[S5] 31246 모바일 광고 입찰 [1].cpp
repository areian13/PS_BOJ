#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountMoloco(int x, vector<int>& a, vector<int>& b)
{
    int n = a.size();

    int result = 0;
    for (int i = 0; i < n; i++)
        result += (a[i] + x >= b[i]);
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int start = 0;
    int end = 1'000'000'000;
    int result = end;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int cnt = CountMoloco(mid, a, b);
        if (cnt < k)
            start = mid + 1;
        else
        {
            result = min(result, mid);
            end = mid - 1;
        }
    }

    cout << result << '\n';
}