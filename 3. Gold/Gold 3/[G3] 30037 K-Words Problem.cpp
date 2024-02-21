#ifdef ONLINE_JUDGE
#define _128d  __int128
#else
#define _128d long long
#endif

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <random>
#include <type_traits>
#include <numeric>
#include <functional>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;
typedef long double LDOUBLE;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

template <typename T, size_t N>
ostream& operator<<(ostream& os, array<T, N>& vec)
{
    for (T& value : vec)
        os << value << ' ';
    return os;
}

bool IsSign(char c)
{
    return c == '!' || c == '?' || c == ',' || c == '.';
}
bool IsSign(string str)
{
    if (str.size() != 1)
        return false;
    return IsSign(str[0]);
}

void Change(vector<string>& words)
{
    while (true)
    {
        bool isChanged = false;
        int n = words.size();

        For(n)
        {
            if (i > 0 && words[i] == "of" && words[i + 1] == "Korea" && !IsSign(words[i - 1]))
            {
                isChanged = true;

                if (among('a', words[i - 1][0], 'z'))
                    words[i - 1][0] -= 32;

                words.erase(words.begin() + i + 1);
                words.erase(words.begin() + i);
                words[i - 1] = "K-" + words[i - 1];
                break;
            }
        }
        if (!isChanged)
            break;
    }

    while (true)
    {
        bool isChanged = false;
        int n = words.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (words[i] == "Korea" && !IsSign(words[i + 1]))
            {
                isChanged = true;

                if (among('a', words[i + 1][0], 'z'))
                    words[i + 1][0] -= 32;

                words[i + 1] = "K-" + words[i + 1];
                words.erase(words.begin() + i);
                break;
            }
        }
        if (!isChanged)
            break;
    }
}

int main()
{
    FastIO;

    int tc;
    Cin tc;

    cin.ignore();
    while (tc--)
    {
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;
        while (ss >> word)
        {
            if (IsSign(word.back()))
            {
                words.push_back(word.substr(0, word.size() - 1));
                words.push_back(word.substr(word.size() - 1, 1));
            }
            else
                words.push_back(word);
        }

        Change(words);

        For(words.size())
        {
            Cout words[i];
            if (IsSign(words[i + 1]))
            {
                Cout words[i + 1] fspc;
                i++;
            }
            else
                Cout " ";
        }
        Enter;
    }
}