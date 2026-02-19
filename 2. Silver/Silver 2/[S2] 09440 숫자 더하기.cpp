#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<char> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), greater<char>());

        string a, b;
        for (int i = 0; i < n; i++)
            (i & 1 ? a : b) += v[i];
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i0 = a.rfind('0') + 1;
        int i1 = b.rfind('0') + 1;
        if (i0 != -1) swap(a[0], a[i0]);
        if (i1 != -1) swap(b[0], b[i1]);

        if (a.size() != b.size())
        {
            char p = min(a[0], b[0]), q = max(a[0], b[0]);
            (a.size() < b.size() ? (a[0] = q, b[0] = p) : (a[0] = p, b[0] = q));
        }

        long long result = stoll(a) + stoll(b);
        cout << result << '\n';
    }
}