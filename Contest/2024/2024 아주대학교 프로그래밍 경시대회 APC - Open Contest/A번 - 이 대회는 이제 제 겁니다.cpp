#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, p, c;
    cin >> a >> p >> c;

    int result = max(a + c, p);
    cout << result << '\n';
}