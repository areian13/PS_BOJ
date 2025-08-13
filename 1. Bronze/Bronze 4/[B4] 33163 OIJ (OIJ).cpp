#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string joi = "JOI";

    int n;
    string s;
    cin >> n >> s;

    for (char c : s)
        cout << joi[(joi.find(c) + 1) % 3];
}