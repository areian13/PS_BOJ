#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    char result = (a * b == c * d) ? 'E' : ((a * b > c * d) ? 'M' : 'P');
    cout << result << '\n';
}