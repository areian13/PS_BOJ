#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long MaxSeg(int start, int end, int idx, int left, int right, vector<long long>& maxSeg)
{
    if (end < left || right < start)
        return 0;
    if (start <= left && right <= end)
        return maxSeg[idx];
    int mid = (left + right) / 2;
    return max(MaxSeg(start, end, 2 * idx, left, mid, maxSeg),
        MaxSeg(start, end, 2 * idx + 1, mid + 1, right, maxSeg));
}

long long MinSeg(int start, int end, int idx, int left, int right, vector<long long>& minSeg)
{
    if (end < left || right < start)
        return LLONG_MAX;
    if (start <= left && right <= end)
        return minSeg[idx];
    int mid = (left + right) / 2;
    return min(MinSeg(start, end, 2 * idx, left, mid, minSeg),
        MinSeg(start, end, 2 * idx + 1, mid + 1, right, minSeg));
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;
    int r = log2(n * 2 - 1);
    int size = pow(2, r);

    vector<long long> maxSeg(2 * size, 0);
    vector<long long> minSeg(2 * size, LLONG_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> maxSeg[size + i];
        minSeg[size + i] = maxSeg[size + i];
    }

    for (int i = size - 1; i > 0; i--)
    {
        maxSeg[i] = max(maxSeg[i * 2], maxSeg[i * 2 + 1]);
        minSeg[i] = min(minSeg[i * 2], minSeg[i * 2 + 1]);
    }

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;

        array<long long, 2> result = 
        { 
            MinSeg(start, end, 1, 1, size - 1, minSeg),
            MaxSeg(start, end, 1, 1, size - 1, maxSeg) 
        };
        cout << result[0] << ' ' << result[1] << '\n';
    }
}