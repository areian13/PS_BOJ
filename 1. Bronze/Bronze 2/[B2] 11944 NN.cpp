#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    string result = "";
    string sn = to_string(n);
    for (int i = 0; i < n; i++)
        result += sn;

    result = result.substr(0, m);
    cout << result << '\n';
}