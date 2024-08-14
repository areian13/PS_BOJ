#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<char, string> clup;
    clup['M'] = "MatKor";
    clup['W'] = "WiCys";
    clup['C'] = "CyKor";
    clup['A'] = "AlKor";
    clup['$'] = "$clear";

    char c;
    cin >> c;

    string result = clup[c];
    cout << result << '\n';
}