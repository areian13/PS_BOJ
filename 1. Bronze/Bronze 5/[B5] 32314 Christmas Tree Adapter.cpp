#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, w, v;
    cin >> a >> w >> v;

    bool result = (a <= w / v);
    cout << result << '\n';
}