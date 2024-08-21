#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string n;
    cin >> n;

    int k = n.size() / 2;
    array<string, 2> result = { n.substr(0, k), n.substr(k, k) };
    cout << result[0] << ' ' << result[1] << '\n';
}