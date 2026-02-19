#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int RSP(int a, int b)
{
    if (a == 1 || a == 3 || a == 4)
        a = -1;
    if (b == 1 || b == 3 || b == 4)
        b = -1;
    if (a == b) return 0;
    if (a == -1 && b != -1) return +1;
    if (a != -1 && b == -1) return -1;

    if (a == 0 && b == 5) return +1;
    if (a == 5 && b == 2) return +1;
    if (a == 2 && b == 0) return +1;
    return -1;
}

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = RSP(a, b);
    cout << (result == 0 ? '=' : (result > 0 ? '<' : '>')) << '\n';
}