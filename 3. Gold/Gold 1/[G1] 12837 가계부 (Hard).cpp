#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long SegTree(int start, int end, int idx, int left, int right, vector<long long>& arr)
{
    if (end < left || right < start)
        return 0;
    if (start <= left && right <= end)
        return arr[idx];

    int mid = (left + right) / 2;

    return SegTree(start, end, 2 * idx, left, mid, arr) + SegTree(start, end, 2 * idx + 1, mid + 1, right, arr);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int t = bit_ceil((unsigned int)n);

    vector<long long> arr(t * 2, 0);
    for (int i = 0; i < m; i++)
    {
        int type, p, q;
        cin >> type >> p >> q;

        if (type == 1)
        {
            p += t - 1;
            arr[p] += q;

            while (p > 1)
            {
                p /= 2;
                arr[p] = arr[p * 2] + arr[p * 2 + 1];
            }
        }
        else
        {
            long long result = SegTree(p - 1, q - 1, 1, 0, t - 1, arr);
            cout << result << '\n';
        }
    }
}