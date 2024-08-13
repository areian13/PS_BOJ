#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h, m;
    cin >> h >> m;

    int result = h * 60 + m;
    cout << result << '\n';
}