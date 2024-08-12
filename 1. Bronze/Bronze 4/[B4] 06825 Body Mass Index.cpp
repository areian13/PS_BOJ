#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    double w, h;
    cin >> w >> h;

    double bmi = w / h / h;
    string result = (bmi >= 25 ? "Overweight" : bmi < 18.5 ? "Underweight" : "Normal weight");
    cout << result << '\n';
}