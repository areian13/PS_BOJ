#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    string result = s;
    reverse(result.begin() + a - 1, result.begin() + b);
    cout << result << '\n';
}