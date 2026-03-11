#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> l(n);
        for (int i = 0; i < n; i++)
            cin >> l[i];
        sort(l.begin(), l.end());

        vector<int> s;
        s.reserve(n);
        for (int i = 0; i < n; i += 2)
            s.push_back(l[i]);
        for (int i = n - 1 - (n & 1); i >= 0; i -= 2)
            s.push_back(l[i]);

        int result = 0;
        for (int i = 0; i < n; i++)
            result = max(result, abs(s[i] - s[(i + 1) % n]));
        cout << result << '\n';
    }
}