#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    int n;
    cin >> s >> n;

    char result = s[n - 1];
    cout << result << '\n';
}