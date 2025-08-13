#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int result = accumulate(v.begin(), v.end(), 0) - *max_element(v.begin(), v.end());
    cout << result << '\n';
}