#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int A(int a)
{
    if (a == 0)
        return 0;
    if (a == 1)
        return 5'000'000;
    if (a <= 3)
        return 3'000'000;
    if (a <= 6)
        return 2'000'000;
    if (a <= 10)
        return 500'000;
    if (a <= 15)
        return 300'000;
    if (a <= 21)
        return 100'000;
    return 0;
}
int B(int b)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return 5'120'000;
    if (b <= 3)
        return 2'560'000;
    if (b <= 7)
        return 1'280'000;
    if (b <= 15)
        return 640'000;
    if (b <= 31)
        return 320'000;
    return 0;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int a, b;
        cin >> a >> b;

        int result = A(a) + B(b);
        cout << result << '\n';
    }
}