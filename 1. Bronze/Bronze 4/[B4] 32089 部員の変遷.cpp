#include <iostream>
#include <vector>
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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int result = 0;
        for (int i = 2; i < n; i++)
            result = max(result, a[i] + a[i - 1] + a[i - 2]);
        cout << result << '\n';
    }
}