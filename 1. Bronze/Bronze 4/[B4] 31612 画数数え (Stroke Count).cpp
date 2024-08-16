#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountStroke(string& s)
{
    array<int, 26> stroke = { 0, };
    stroke['j' - 'a'] = 2;
    stroke['o' - 'a'] = 1;
    stroke['i' - 'a'] = 2;

    int result = 0;
    for (char c : s)
        result += stroke[c - 'a'];
    return result;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = CountStroke(s);
    cout << result << '\n';
}