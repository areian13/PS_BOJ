#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, int> cntSwap;
    cntSwap["1()"] = 1;
    cntSwap["(1)"] = 0;
    cntSwap["()1"] = 1;
    cntSwap["1)("] = 1;
    cntSwap[")1("] = 2;
    cntSwap[")(1"] = 1;

    string s;
    cin >> s;

    int result = cntSwap[s];
    cout << result << '\n';
}