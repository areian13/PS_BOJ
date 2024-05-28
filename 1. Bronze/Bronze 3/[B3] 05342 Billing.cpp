#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unordered_map<string, double> items;
    items["Paper"] = 57.99;
    items["Printer"] = 120.50;
    items["Planners"] = 31.25;
    items["Binders"] = 22.50;
    items["Calendar"] = 10.95;
    items["Notebooks"] = 11.20;
    items["Ink"] = 66.95;

    double result = 0;
    while (true)
    {
        string item;
        cin >> item;

        if (item == "EOI")
            break;
        result += items[item];
    }
    printf("$%.2lf\n", result);
}