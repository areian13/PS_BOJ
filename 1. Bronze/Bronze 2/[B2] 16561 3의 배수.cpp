#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 3; i < n; i += 3)
    {
        for (int j = 3; i + j < n; j += 3)
        {
            for (int k = 3; i + j + k <= n; k += 3)
                result += (i + j + k == n);
        }
    }
    cout << result << '\n';
}