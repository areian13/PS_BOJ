#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = n;
    while (result % 2 == 1)
        result = (result + 1) / 2;
    cout << result << '\n';
}