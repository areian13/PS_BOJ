#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool NotEmpty(int a, int b, int c, int n)
{
    for (int i = 0; a * i <= n; i++)
    {
        for (int j = 0; a * i + b * j <= n; j++)
        {
            for (int k = 0; a * i + b * j + c * k <= n; k++)
            {
                if (a * i + b * j + c * k == n)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    FastIO;

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    bool result = NotEmpty(a, b, c, n);
    cout << result << '\n';
}