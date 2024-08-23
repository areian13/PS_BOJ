#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    char c;
    cin >> c;

    int result = abs(c - 'I') + 84;
    cout << result << '\n';
}