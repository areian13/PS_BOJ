#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountSumIsS(int k, int sum, int s, vector<int>& a)
{
    int n = a.size();

    if (k == n)
        return 0;

    int result = 0;
    if (sum + a[k] == s)
        result++;

    result += CountSumIsS(k + 1, sum, s, a);
    result += CountSumIsS(k + 1, sum + a[k], s, a);
    return result;
}

int main()
{
    FastIO;

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = CountSumIsS(0, 0, s, a);
    cout << result << '\n';
}