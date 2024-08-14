#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    array<int, 2> result = { a + b - c,stoi(to_string(a) + to_string(b)) - c };
    cout << result[0] << '\n';
    cout << result[1] << '\n';
}