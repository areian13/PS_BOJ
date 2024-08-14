#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, string> cry;
    cry["SONGDO"] = "HIGHSCHOOL";
    cry["CODE"] = "MASTER";
    cry["2023"] = "0611";
    cry["ALGORITHM"] = "CONTEST";

    string str;
    cin >> str;

    string result = cry[str];
    cout << result << '\n';
}