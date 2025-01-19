#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const double PI = acos(-1);

int main()
{
    FastIO;

    while (true)
    {
        string line;
        getline(cin, line);

        if (cin.eof())
            break;

        stringstream ss(line);
        vector<string> s;
        string temp;
        while (ss >> temp)
            s.push_back(temp);

        int w = stoi(s[1]);
        int r = stoi(s[3]);
        int d = stoi(s.back());

        double h = w * r / 100.0;
        int result = round((d * 2.54 + (h * 2) / 10.0) * PI);
        printf("%s: %d\n", line.c_str(), result);
    }
}