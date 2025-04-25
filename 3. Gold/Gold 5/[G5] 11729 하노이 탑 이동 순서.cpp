#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void PrintHanoi(int n, int s, int m, int e)
{
    if (n == 0)
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

    cout << ((1 << n) - 1) << '\n';
    PrintHanoi(n, 1, 2, 3);
}