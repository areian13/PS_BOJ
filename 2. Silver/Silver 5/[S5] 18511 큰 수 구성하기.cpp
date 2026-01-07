#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int FindLessMax(int v, int n, vector<int>& a)
{
    if (v > n) return 0;

    int result = v;
    for (int d : a)
        result = max(result, FindLessMax(v * 10 + d, n, a));
    return result;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    for (int i = 0; i < k; i++)
        cin >> a[i];

    int result = FindLessMax(0, n, a);
    cout << result << '\n';
}