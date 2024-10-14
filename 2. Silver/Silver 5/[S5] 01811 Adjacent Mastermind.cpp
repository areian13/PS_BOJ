#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountBlack(int n, vector<bool>& isUsedG, vector<bool>& isUsedT, string& guess, string& target)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (guess[i] == target[i])
        {
            result++;
            isUsedG[i] = true;
            isUsedT[i] = true;
        }
    }
    return result;
}

int CountGrey(int n, vector<bool>& isUsedG, vector<bool>& isUsedT, string& guess, string& target)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (isUsedG[i])
            continue;

        if (0 < i && guess[i] == target[i - 1] && !isUsedT[i - 1])
        {
            result++;
            isUsedG[i] = true;
            isUsedT[i - 1] = true;
        }
        else if (i < n - 1 && guess[i] == target[i + 1] && !isUsedT[i + 1])
        {
            result++;
            isUsedG[i] = true;
            isUsedT[i + 1] = true;
        }
    }
    return result;
}
int CountWhite(int n, vector<bool>& isUsedG, vector<bool>& isUsedT, string& guess, string& target)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (isUsedG[i])
            continue;

        for (int j = 0; j < n; j++)
        {
            if (guess[i] == target[j] && !isUsedT[j])
            {
                result++;
                isUsedG[i] = true;
                isUsedT[j] = true;
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        string target;
        cin >> target;
        if (target == "#")
            break;

        string guess;
        cin >> guess;

        int n = target.size();
        vector<bool> isUsedG(n, false);
        vector<bool> isUsedT(n, false);

        int b = CountBlack(n, isUsedG, isUsedT, guess, target);
        int g = CountGrey(n, isUsedG, isUsedT, guess, target);
        int w = CountWhite(n, isUsedG, isUsedT, guess, target);

        printf("%s: %d black, %d grey, %d white\n", guess.c_str(), b, g, w);
    }
}