#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "#")
            break;

        int result = 0;
        while (true)
        {
            if (s == "0")
                break;

            stringstream ss(s);
            string mileStr;
            ss >> mileStr >> mileStr >> mileStr;
            int mile = stoi(mileStr);

            string type;
            ss >> type;

            result += (type == "Y" ? max(mile, 500) : ceil(mile * (type == "F" ? 2.0 : 1.5)));

            getline(cin, s);
        }

        cout << result << '\n';
    }
}