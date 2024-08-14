#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    string result = (a == b ? "Anything" : (a < b ? "Bus" : "Subway"));
    cout << result << '\n';
}