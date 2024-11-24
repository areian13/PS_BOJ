#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, bool> ignore;
    ignore["i"] = true;
    ignore["pa"] = true;
    ignore["te"] = true;
    ignore["ni"] = true;
    ignore["niti"] = true;
    ignore["a"] = true;
    ignore["ali"] = true;
    ignore["nego"] = true;
    ignore["no"] = true;
    ignore["ili"] = true;

    string s;
    getline(cin, s);

    stringstream ss(s);
    string temp;
    string result = "";
    while (ss >> temp)
    {
        if (result == "" || ignore.count(temp) == 0)
            result += temp[0] - 32;
    }
    cout << result << '\n';
}