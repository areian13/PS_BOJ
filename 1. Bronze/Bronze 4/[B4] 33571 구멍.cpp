#include <iostream>
#include <map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

map<char, int> h;

int main()
{
    FastIO;

    for (char c : "AabDdegOoPpQqR@")
        h[c] = 1;
    h['B'] = 2;

    string s;
    getline(cin, s);

    int result = 0;
    for (char c : s)
        result += h[c];
    cout << result << '\n';
}