#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    double v, w, h;
    cin >> v >> w >> h;

    int result = log(pow(v / w, 2) * 9 / 80 * h + 1) / log(25 / 16.0);
    cout << result << '\n';
}