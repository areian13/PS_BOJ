#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    int result = log10(a + b) + 1;
    cout << result << '\n';
}