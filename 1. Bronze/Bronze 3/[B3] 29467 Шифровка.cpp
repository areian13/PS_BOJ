#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    string result = "";
    for (int i = 0; i < n; i++)
        result = max(result, s.substr(i, s.size() - i));
    cout << result << '\n';
}