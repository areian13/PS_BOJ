#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Merge(int s, int m, int e, vector<int>& a, vector<int>& temp)
{
    long long result = 0;
    int i = s, j = m + 1, k = s;
    while (i <= m && j <= e)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
        {
            result += j - k;
            temp[k++] = a[j++];
        }
    }

    if (i <= m)
    {
        for (int t = i; t <= m; t++)
            temp[k++] = a[t];
    }
    else
    {
        for (int t = j; t <= e; t++)
            temp[k++] = a[t];
    }

    for (int t = s; t <= e; t++)
        a[t] = temp[t];
    return result;
}

long long MergeSort(int s, int e, vector<int>& a, vector<int>& temp)
{
    if (s >= e)
        return 0;

    int m = (s + e) / 2;
    long long result = MergeSort(s, m, a, temp) + MergeSort(m + 1, e, a, temp);
    result += Merge(s, m, e, a, temp);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n), temp(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long result = MergeSort(0, n - 1, a, temp);
    cout << result << '\n';
}