#include <iostream>
#include <map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

map<char, string> r = {
    {'A',"a"},
    {'B',"v"},
    {'E',"ye"},
    {'K',"k"},
    {'M',"m"},
    {'H',"n"},
    {'O',"o"},
    {'P',"r"},
    {'C',"s"},
    {'T',"t"},
    {'Y',"u"},
    {'X',"h"},
};

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = "";
    for (char c : s)
        result += r[c];
    cout << result << '\n';
}