#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;


int main()
{
    FastIO;

    vector<string> ks = {
        "1QAZ","2WSX","3EDC","4RFV5TGB",
        "6YHN7UJM","8IK,","9OL.","0P;/-[\'=]"
    };
    unordered_map<char, int> k;
    for (int i = 0; i < 8; i++)
    {
        for (char c : ks[i])
            k[c] = i;
    }

    string s;
    cin >> s;

    array<int, 8> result = { 0, };
    for (char c : s)
        result[k[c]]++;

    for (int i = 0; i < 8; i++)
        cout << result[i] << '\n';
}