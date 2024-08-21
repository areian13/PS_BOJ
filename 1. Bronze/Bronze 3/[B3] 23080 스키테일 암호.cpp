#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int k;
    string s;
    cin >> k >> s;

    int n = s.size();

    string result = "";
    for (int i = 0; i < n; i += k)
        result += s[i];
    cout << result << '\n';
}