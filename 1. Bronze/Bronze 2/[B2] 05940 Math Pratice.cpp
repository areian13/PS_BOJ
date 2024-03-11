#include <iostream>
#include <cmath>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int E(int a, int b)
{
    for (int i = a + 1; i <= 62; i++)
    {
        long long value = pow(2, i);
        if (to_string(value)[0] == b + '0')
            return i;
    }
    return false;
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = E(a, b);
    cout << result << '\n';
}