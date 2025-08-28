#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string x;
    cin >> x;

    if (x[0] == '0' && x[1] == 'x')
        x = to_string(stoi(x.substr(2), nullptr, 16));
    else if (x[0] == '0')
        x = to_string(stoi(x.substr(1), nullptr, 8));
    cout << x << '\n';
}