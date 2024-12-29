#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int result = (a + b + c + d - 2) % 4 + 1;
    cout << result << '\n';
}