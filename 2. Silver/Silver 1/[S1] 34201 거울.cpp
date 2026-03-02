#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    long long s;
    cin >> n >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n - 1, t = n & 1;
    while (l <= r)
    {
        s = 2 * a[t ? r-- : l++] - s;
        t ^= 1;
    }
    cout << s << '\n';
}