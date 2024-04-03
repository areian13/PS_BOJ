#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Count369(int n)
{
    int result = 0;
    while (n > 0)
    {
        int k = n % 10;
        result += (k != 0 && k % 3 == 0);
        n /= 10;
    }
    return result;
}

int CountClap(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
        result += Count369(i);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = CountClap(n);
    cout << result << '\n';
}