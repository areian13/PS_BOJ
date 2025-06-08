#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int t1, t2;
    cin >> t1 >> t2;

    int result = min(t1, t2);
    cout << result << '\n';
}