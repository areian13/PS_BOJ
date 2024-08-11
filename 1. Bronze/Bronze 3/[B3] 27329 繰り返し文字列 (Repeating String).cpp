#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = (s.substr(0, n / 2) == s.substr(n / 2, n / 2) ? "Yes" : "No");
    cout << result << '\n';
}