#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    int result = 0;
    int sum = 0;
    while (sum < c)
    {
        result++;
        sum += a;
        if (result % 7 == 0)
            sum += b;
    }
    cout << result << '\n';
}