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

    vector<int> rope(n);
    for (int i = 0; i < n; i++)
        cin >> rope[i];
    sort(rope.begin(), rope.end());

    int result = 0;
    for (int i = 0; i < n; i++)
        result = max(result, rope[i] * (n - i));
    cout << result << '\n';
}