#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 3'000'000;

void Update(int i, int v, vector<int>& seg)
{
    int t = seg.size() / 2;
    i += t;
    seg[i] = v;

    while (i > 1)
    {
        i /= 2;
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}
int Kth(int k, vector<int>& seg)
{
    int t = seg.size() / 2;
    int i = 1;
    while (i < t)
    {
        if (k <= seg[i * 2])
            i = i * 2;
        else
        {
            k -= seg[i * 2];
            i = i * 2 + 1;
        }
    }
    return i - t;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> s(MAX + 1, 0), l(n, 0);
    for (int v : {1, 2, 5})
    {
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;

            s[l[i]] += v;
            s[l[i] + k] -= v;
            l[i] += k;
        }
    }
    for (int i = 1; i <= MAX; i++)
        s[i] += s[i - 1];

    int QC;
    cin >> QC;

    constexpr int t = bit_ceil(1u * MAX);
    vector<int> seg(t * 2, 1);
    for (int i = t - 1; i >= 1; i--)
        seg[i] = seg[i * 2] + seg[i * 2 + 1];

    for (int qc = 1; qc <= QC; qc++)
    {
        int q;
        cin >> q;

        int k = Kth(q, seg);
        long long result = s[k];
        cout << result << '\n';
        Update(k, 0, seg);
    }
}