#include <iostream>
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

        int result = n;
        while (n != 1)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = n * 3 + 1;
            result = max(result, n);
        }
        cout << result << '\n';
    }
}