#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    int result = 0;
    while (n != 1)
    {
        n = (n % 2 == 0 ? n / 2 : n + 1);
        result++;
    }
    cout << result << '\n';
}