#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t, v;
    cin >> t >> v;

    int result = t * v;
    cout << result << '\n';
}