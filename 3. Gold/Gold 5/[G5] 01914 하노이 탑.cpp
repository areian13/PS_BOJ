#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#ifdef ONLINE_JUDGE
#define __int128  __int128
#include <string>

ostream& operator<<(ostream& os, __int128 value)
{
    bool isNega = value < 0;
    if (isNega)
        value = -value;

    string result = "";
    do
    {
        result += (value % 10 + '0');
        value /= 10;
    } while (value > 0);

    if (isNega)
        result += '-';
    reverse(result.begin(), result.end());
    return os << result;
}

#else
#define __int128 long long
#endif

void PrintHanoi(int n, int s, int m, int e)
{
    if (n <= 0)
        return;

    PrintHanoi(n - 1, s, e, m);
    cout << s << ' ' << e << '\n';
    PrintHanoi(n - 1, m, s, e);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    __int128 k = ((__int128)1 << n) - 1;
    cout << k << '\n';

    if (n <= 20)
        PrintHanoi(n, 1, 2, 3);
}