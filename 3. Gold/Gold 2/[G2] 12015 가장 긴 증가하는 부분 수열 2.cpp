#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Elem
{
    int value, idx;

    friend bool operator<(const Elem& a, const Elem& b)
    {
        if (a.value != b.value)
            return a.value < b.value;
        return a.idx > b.idx;
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
        arr[idx] = max(arr[idx * 2], arr[idx * 2 + 1]);
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Elem> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].value;
        a[i].idx = i;
    }
    sort(a.begin(), a.end());

    int r = log2(n * 2 - 1);
    int size = pow(2, r);

    vector<int> arr(size * 2, 0);
    for (int i = 0; i < n; i++)
        Update(a[i].idx + size, LIS(0, a[i].idx, 1, 0, size - 1, arr) + 1, arr);

    int result = arr[1];
    cout << result << '\n';
}