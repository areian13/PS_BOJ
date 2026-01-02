#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int y, c, p;
    cin >> y >> c >> p;

    int result = min({ y,c / 2,p });
    cout << result << '\n';
}