#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, d;
    cin >> a >> b >> d;

    int result = d * ((a * b) / 12 + ((a * b) % 12 != 0));
    cout << result << '\n';
}