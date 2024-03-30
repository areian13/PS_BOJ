#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t;
    cin >> t;

    int result = t * t / 4.0 + 0.5;
    cout << result << '\n';
}