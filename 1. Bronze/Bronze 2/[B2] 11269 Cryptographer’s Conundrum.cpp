#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    int result = 0;
    for (int i = 0; i < n; i++)
        result += (s[i] != "PER"[i % 3]);
    cout << result << '\n';
}