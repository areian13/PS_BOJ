#include <iostream>
#include <map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

map<char, string> liberal = {
    {'F',"Foundation"},
    {'C',"Claves"},
    {'V',"Veritas"},
    {'E',"Exploration"},
};

int main()
{
    FastIO;

    string s;
    cin >> s;

    cout << liberal[s[0]] << '\n';
}