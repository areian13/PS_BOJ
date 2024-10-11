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

    string result(n, '\0');
    for (int i = 0; i < n; i++)
        result[i] = s[i] ^ 32;
    cout << result << '\n';
}