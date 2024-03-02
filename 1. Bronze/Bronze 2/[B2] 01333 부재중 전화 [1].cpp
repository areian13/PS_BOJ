#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CallTime(int n, int l, int d)
{
    for (int i = 0; i < n; i++)
    {
        int start = i * (l + 5) + l;
        for (int j = 0; j < 5; j++)
        {
            if ((start + j) % d == 0)
                return start + j;
        }
    }

    int result = 0;
    while (result < n * (l + 5))
        result += d;
    return result;
}

int main()
{
    int n, l, d;
    cin >> n >> l >> d;

    int result = CallTime(n, l, d);
    cout << result << '\n';
}