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

    vector<int> a(n * 3);
    for (int i = 0; i < n * 3; i++)
        cin >> a[i];

    nth_element(a.begin(), a.begin() + n * 2 - 1, a.end());
    nth_element(a.begin(), a.begin() + n, a.end());
    int result = a[n * 2 - 1] - a[n];
    cout << result << '\n';
}