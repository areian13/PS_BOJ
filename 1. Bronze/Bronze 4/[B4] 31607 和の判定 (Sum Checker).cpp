#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    bool result = (max({ a,b,c }) * 2 == a + b + c);
    cout << result << '\n';
}