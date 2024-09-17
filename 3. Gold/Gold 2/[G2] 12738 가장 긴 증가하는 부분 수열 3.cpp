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

    vector<int> l(n, 0);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        auto p = lower_bound(l.begin(), l.begin() + result, a);
        *p = a;

        if (p == l.begin() + result)
            result++;
    }
    cout << result << '\n';
}