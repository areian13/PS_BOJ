#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    while (n > 0)
    {
        for (int i = 1; i <= n; i++)
        {
            n -= i;
            result++;
        }
    }
    cout << result << '\n';
}