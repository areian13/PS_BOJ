#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int result = 0;
    int l = 0, r = 0, c = 0;
    while (l <= r && r < n)
    {
        if (~s[r] & 1)
            r++;
        else
        {
            if (c < k) r++, c++;
            else c -= (s[l] & 1), l++;
        }

        result = max(result, r - l - c);
    }
    cout << result << '\n';
}