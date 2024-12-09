#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int sab, ma, fab, mb;
    cin >> sab >> ma >> fab >> mb;

    bool result = (sab <= max(ma + fab + mb, 240));
    if (result)
        cout << "high speed rail" << '\n';
    else
        cout << "flight" << '\n';
}