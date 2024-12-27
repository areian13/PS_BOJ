#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int b, c;
    cin >> b >> c;

    long long result = 0;
    for (int i = 0; i < n; i++)
        result += 1 + (max(a[i] - b, 0) + c - 1) / c;
    cout << result << '\n';
}