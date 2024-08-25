#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b, c;
    cin >> a >> b >> c;

    string result = a + b + c;
    if (result[1] == result[2])
        result[2] = '\'';
    if (result[3] == result[4])
        result[4] = '\'';
    cout << result << '\n';
}