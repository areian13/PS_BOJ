#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsConstrast(int x1, int x2, int n)
{
    double k = (x1 - x2) / 2.0;

    return (k == (int)k && k >= n);
}

int main()
{
    FastIO;

    int x1, x2, n;
    cin>> x1 >> x2 >> n;

    string result = (IsConstrast(x1, x2, n) ? "YES" : "NO");
    cout << result << '\n';
}