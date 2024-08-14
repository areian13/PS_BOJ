#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Color(int l)
{
    if (l >= 620)
        return "Red";
    if (l >= 590)
        return "Orange";
    if (l >= 570)
        return "Yellow";
    if (l >= 495)
        return "Green";
    if (l >= 450)
        return "Blue";
    if (l >= 425)
        return "Indigo";
    return "Violet";
}

int main()
{
    FastIO;

    int l;
    cin >> l;

    string result = Color(l);
    cout << result << '\n';
}