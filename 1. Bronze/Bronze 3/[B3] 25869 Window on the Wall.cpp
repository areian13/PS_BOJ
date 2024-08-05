#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int w, h, d;
    cin >> w >> h >> d;

    int result = max(w - d * 2, 0) * max(h - d * 2, 0);
    cout << result << '\n';
}