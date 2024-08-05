#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    int result = 1;
    for (int i = 0; i < 4; i++)
        result <<= (a[i] != b[i]);
    cout << result << '\n';
}