#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

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

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> result = { 0,0 };
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                continue;
            if (abs(a[i] - b[i]) == 1)
                result[a[i] > b[i]] += (a[i] + b[i] == 3 ? 6 : a[i] + b[i]);
            else
                result[a[i] < b[i]] += max(a[i], b[i]);
        }
        printf("A has %d points. B has %d points.\n\n", result[0], result[1]);
    }
}