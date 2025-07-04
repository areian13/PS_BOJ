#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

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

        vector<int> cnt(n + 1, 0);
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            char c;
            cin >> c;

            cnt[i] = (c == 'X' ? cnt[i - 1] + 1 : 0);
            result = max(result, cnt[i]);
        }
        printf("The longest contiguous subsequence of X's is of length %d\n", result);
    }
}