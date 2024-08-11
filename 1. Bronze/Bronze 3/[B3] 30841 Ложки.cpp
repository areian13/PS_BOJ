#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b;
    cin >> a >> b;

    long long result = (a + b == 0 ? 0 : (a * b) / (a + b));
    cout << result << '\n';
}