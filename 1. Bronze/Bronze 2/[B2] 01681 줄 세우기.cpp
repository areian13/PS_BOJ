#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool isIn(int l, int n)
{
    while (n > 0)
    {
        if (n % 10 == l)
            return true;
        n /= 10;
    }
    return false;
}

int main()
{
    FastIO;

    int n, l;
    cin >> n >> l;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        while (isIn(l, result + 1))
            result++;
        result++;
    }
    cout << result << '\n';
}