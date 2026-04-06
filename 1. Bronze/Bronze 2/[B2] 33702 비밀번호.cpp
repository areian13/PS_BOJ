#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k;
    cin >> k;

    int result = (k & 1 ? 8 : 0);
    cout << result << '\n';
}