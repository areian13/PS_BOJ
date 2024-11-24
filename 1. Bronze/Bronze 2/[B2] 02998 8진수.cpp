#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

unordered_map<string, char> binToOct;

int main()
{
    FastIO;

    binToOct["000"] = '0';
    binToOct["001"] = '1';
    binToOct["010"] = '2';
    binToOct["011"] = '3';
    binToOct["100"] = '4';
    binToOct["101"] = '5';
    binToOct["110"] = '6';
    binToOct["111"] = '7';


    string bin;
    cin >> bin;

    while (bin.size() % 3 != 0)
        bin = '0' + bin;

    string result = "";
    for (int i = 0; bin[i] != '\0'; i += 3)
        result += binToOct[bin.substr(i, 3)];
    cout << result << '\n';
}