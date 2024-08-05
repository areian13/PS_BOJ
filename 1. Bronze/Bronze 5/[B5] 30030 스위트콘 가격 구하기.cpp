#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int b;
    cin >> b;

    int result = b * 10 / 11;
    cout << result << '\n';
}