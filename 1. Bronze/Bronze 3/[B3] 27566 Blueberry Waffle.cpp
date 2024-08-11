#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int r, f;
    cin >> r >> f;

    int cnt = f / r;
    double l = (double)f / r - cnt;

    string result = (((cnt % 2 == 0) && (l < 0.5)) || ((cnt % 2 == 1) && (l > 0.5)) ? "up" : "down");
    cout << result << '\n';
}