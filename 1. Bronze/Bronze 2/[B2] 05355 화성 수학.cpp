#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;
    cin.ignore();

    for (int tc = 1; tc <= TC; tc++)
    {
        string form;
        getline(cin, form);

        stringstream ss(form);
        string temp;
        ss >> temp;
        double result = stod(temp);
        while (ss >> temp)
        {
            if (temp == "@")
                result *= 3;
            else if (temp == "%")
                result += 5;
            else if (temp == "#")
                result -= 7;
        }

        printf("%.2lf\n", result);
    }
}