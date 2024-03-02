#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string str;
        getline(cin, str);

        if (str == "#")
            break;

        stringstream ss(str);
        string temp;
        string result = "";

        while (ss >> temp)
        {
            reverse(temp.begin(), temp.end());
            result += temp;
            result += ' ';
        }
        cout << result << '\n';
    }
}