#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsNum(string& str)
{
    return (str != "Fizz" && str != "Buzz" && str != "FizzBuzz");
}

string MakeFizzBuzz(int n)
{
    if (n % 3 == 0 && n % 5 == 0)
        return "FizzBuzz";
    if (n % 3 == 0)
        return "Fizz";
    if (n % 5 == 0)
        return "Buzz";
    return to_string(n);
}

int main()
{
    FastIO;

    int n = 0;
    for (int i = 0; i < 3; i++)
    {
        string fb;
        cin >> fb;

        if (IsNum(fb))
            n = stoi(fb) + 3 - i;
    }

    string result = MakeFizzBuzz(n);
    cout << result << '\n';
}
