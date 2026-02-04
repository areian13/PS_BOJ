#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;
    k--;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    nth_element(a.begin(), a.begin() + k, a.end());
    cout << a[k] << '\n';
}