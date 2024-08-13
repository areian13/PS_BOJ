#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, y;
    cin >> x >> y;

    int result = x + y + 3;
    cout << result << '\n';
}