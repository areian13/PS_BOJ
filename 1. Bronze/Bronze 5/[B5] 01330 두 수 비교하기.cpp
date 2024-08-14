#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    string result = (a == b) ? "==" : ((a > b) ? ">" : "<");
    cout << result << '\n';
}