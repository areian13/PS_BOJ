#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int s;
        cin >> s;
        s++;

        vector<int> a(s);
        for (int i = 0; i < s; i++)
        {
            char c;
            cin >> c;
            a[i] = c - '0';
        }

        int result = 0;
        int sum = a[0];
        for (int i = 1; i < s; i++)
        {
            int r = max(i - sum, 0);
            result += r;
            sum += a[i] + r;
        }
        printf("Case #%d: %d\n", tc, result);
    }
}