#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();

    string result(n, '\0');
    for (int i = 0; i < n; i++)
        result[i] = max(s1[i], s2[i]);
    cout << result << '\n';
}