#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p, c;
    cin >> p >> c;

    int result = p * 50 - c * 10 + (p > c) * 500;
    cout << result << '\n';
}