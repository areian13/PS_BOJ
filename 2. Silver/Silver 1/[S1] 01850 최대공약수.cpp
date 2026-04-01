#include <iostream>
#include <numeric>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b;
    cin >> a >> b;

    int result = gcd(a, b);
    for (int i = 0; i < result; i++)
        cout << 1;
    cout << '\n';
}