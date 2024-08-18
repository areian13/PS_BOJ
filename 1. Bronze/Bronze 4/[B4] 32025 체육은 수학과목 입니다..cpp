#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h, w;
    cin >> h >> w;

    int result = min(h, w) * 50;
    cout << result << '\n';
}