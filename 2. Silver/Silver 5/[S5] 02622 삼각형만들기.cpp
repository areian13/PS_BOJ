#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int x = (n + 1) / 3; x < (n + 1) / 2; x++)
        result += (x * 3 - n + 2) / 2;
    cout << result << '\n';
}