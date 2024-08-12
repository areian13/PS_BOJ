#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int l, t;
    cin >> l >> t;

    int result = t * 2 - l;
    cout << result << '\n';
}