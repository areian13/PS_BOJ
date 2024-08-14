#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Facto(int n)
{
    if (n <= 1)
        return 1;
    return n * Facto(n - 1);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = Facto(n);
    cout << result << '\n';
}