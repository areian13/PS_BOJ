#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void MakeSums(int s, int e, int sum, vector<int>& sums, vector<int>& a)
{
    if (s > e)
    {
        sums.push_back(sum);
        return;
    }

    MakeSums(s + 1, e, sum, sums, a);
    MakeSums(s + 1, e, sum + a[s], sums, a);
}

int main()
{
    FastIO;

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> left, right;
    MakeSums(0, n / 2, 0, left, a);
    MakeSums(n / 2 + 1, n - 1, 0, right, a);

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    long long result = 0;
    for (int l : left)
    {
        auto u = upper_bound(right.begin(), right.end(), s - l);
        auto d = lower_bound(right.begin(), right.end(), s - l);
        result += u - d;
    }
    result -= (s == 0);
    cout << result << '\n';
}