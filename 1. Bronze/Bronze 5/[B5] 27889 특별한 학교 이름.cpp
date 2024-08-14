#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, string> fullName;
    fullName["NLCS"] = "North London Collegiate School";
    fullName["BHA"] = "Branksome Hall Asia";
    fullName["KIS"] = "Korea International School";
    fullName["SJA"] = "St. Johnsbury Academy";


    string abbrev;
    cin >> abbrev;

    string result = fullName[abbrev];
    cout << result << '\n';
}