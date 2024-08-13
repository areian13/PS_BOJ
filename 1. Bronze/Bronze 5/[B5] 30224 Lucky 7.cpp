#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int LuckyType(int n, int k)
{
    int t = n;
    bool hasK = false;
    do
    {
        hasK |= (t % 10 == k);
        t /= 10;
    } while (t > 0);

    bool isDivisble = (n % k == 0);

    return hasK * 2 + isDivisble;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = LuckyType(n, 7);
    cout << result << '\n';
}