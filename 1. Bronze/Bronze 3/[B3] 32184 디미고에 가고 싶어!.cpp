#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = 0;
    if (a % 2 == 0)
    {
        result++;
        a++;
    }
    if (b % 2 == 1)
    {
        result++;
        b--;
    }
    result += (b - a + 1) / 2;
    cout << result << '\n';
}