#include <iostream>
#include <algorithm>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b;
        cin >> a >> b;

        int n = max(a, b);
        vector<bool> isNode(n + 1, false);
        while (n > 0)
        {
            isNode[n] = true;
            n /= 2;
        }

        int result = min(a, b);
        while (!isNode[result])
            result /= 2;
        result *= 10;
        cout << result << '\n';
    }
}