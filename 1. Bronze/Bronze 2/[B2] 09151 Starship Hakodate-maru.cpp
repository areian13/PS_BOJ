#include <iostream>
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

        int result = 0;
        for (int i = 0; i * i * i <= n; i++)
        {
            for (int j = 0; j * (j + 1) * (j + 2) / 6 <= n; j++)
            {
                int value = i * i * i + j * (j + 1) * (j + 2) / 6;
                if (value > n)
                    break;
                result = max(result, value);

            }
        }
        cout << result << '\n';
    }
}