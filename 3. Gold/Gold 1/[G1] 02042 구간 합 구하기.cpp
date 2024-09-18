#include <iostream>
#include <cmath>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Sum(int start, int end, int left, int right, int idx,
    vector<long long>& arr)
{
    if (right < start || end < left)
        return 0;
    if (start <= left && right <= end)
        return arr[idx];

    int mid = (left + right) / 2;
    return Sum(start, end, left, mid, idx * 2, arr)
        + Sum(start, end, mid + 1, right, idx * 2 + 1, arr);
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    int r = log2(n * 2 - 1);
    int size = pow(2, r);

    vector<long long> arr(size * 2);
    for (int i = 0; i < n; i++)
        cin >> arr[size + i];

    for (int i = size - 1; i > 0; i--)
        arr[i] = arr[i * 2] + arr[i * 2 + 1];

    for (int i = 0; i < m + k; i++)
    {
        int a;
        long long b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            b += size - 1;
            arr[b] = c;
            while (b > 1)
            {
                b /= 2;
                arr[b] = arr[b * 2] + arr[b * 2 + 1];
            }
        }
        else
        {
            b--, c--;

            long long result = Sum(b, c, 0, size - 1, 1, arr);
            cout << result << '\n';
        }
    }
}