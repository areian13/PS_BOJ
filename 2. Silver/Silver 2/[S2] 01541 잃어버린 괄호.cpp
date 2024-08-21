#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsOperator(char op)
{
    return op == '+' || op == '-';
}

int main()
{
    FastIO;

    string formula;
    cin >> formula;
    formula = '+' + formula;

    int n = formula.size();
    bool hasMinus = false;
    for (int i = 0; i < n; i++)
    {
        if (formula[i] == '-')
            hasMinus = true;
        if (hasMinus && formula[i] == '+')
            formula[i] = '-';
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        char op = formula[i];

        string num = "";
        while (i + 1 < n && !IsOperator(formula[i + 1]))
        {
            num += formula[i + 1];
            i++;
        }
        result += stoi(num) * (op == '+' ? +1 : -1);
    }
    cout << result << '\n';
}