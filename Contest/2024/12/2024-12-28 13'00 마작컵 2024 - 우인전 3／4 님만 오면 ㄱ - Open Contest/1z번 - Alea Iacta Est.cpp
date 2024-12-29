#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int result = ((a + b - 1) % 4 + c + d - 1) % 4 + 1;
    cout << result << '\n';
}