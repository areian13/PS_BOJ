#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    bool result = (a + b + c <= 21);
    cout << result << '\n';
}