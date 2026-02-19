#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Duty(int n)
{
    if (n >= 1'000'000) return n *0.20;
    if (n >= 500'000) return n * 0.15;
    if (n >= 100'000) return n * 0.10;
    return n * 0.05;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = Duty(n);
    cout << result << ' ' << n - result << '\n';
}