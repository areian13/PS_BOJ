#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountBundle(int n, int m)
{
    int result = 0;
    while (n > 0)
    {
        result += n;
        n /= m;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = CountBundle(n, m);
    cout << result << '\n';
}