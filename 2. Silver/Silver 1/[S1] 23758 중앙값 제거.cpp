#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin>>n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int k = (n + 1) / 2;
    int result = 0;
    for (int i = 0; i < k; i++)
        result += log2(a[i]);
    result++;
    cout << result << '\n';
}