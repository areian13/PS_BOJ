#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Dic
{
    int value, idx;

    bool operator<(Dic c)
    {
        if (value == c.value)
            return idx > c.idx;
        return value < c.value;
    }
};

int LIS(int start, int end, int idx, int left, int right, vector<int>& arr)
{
    if (end < left || right < start)
        return 0;
    if (start <= left && right <= end)
        return arr[idx];
    int mid = (left + right) / 2;

    return max(LIS(start, end, 2 * idx, left, mid, arr),
        LIS(start, end, 2 * idx + 1, mid + 1, right, arr));
}

void Update(int idx, int value, vector<int>& arr)
{
    arr[idx] = value;
    while (idx > 1)
    {
        idx /= 2;
        arr[idx] = max(arr[2 * idx], arr[2 * idx + 1]);
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Dic> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>> a[i].value;
        a[i].value--;
        a[i].idx = i;
    }
    sort(a.begin(), a.end());

    int t = bit_ceil((unsigned int)n);
    vector<int> arr(t * 2, 0);
    for (int i = 0; i < n; i++)
        Update(a[i].idx + t, LIS(0, a[i].idx, 1, 0, t - 1, arr) + 1, arr);
    cout << n - arr[1] << '\n';
}