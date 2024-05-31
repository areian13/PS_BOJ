#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

#define COUNT 100

double getRand(vector<double>& g)
{
    random_device rd;
    mt19937 gen(rd());

    double lower_bound = g[0];
    double upper_bound = g[1];
    double midpoint = (lower_bound + upper_bound) / 2.0;
    double slope = 2.0 / (upper_bound - lower_bound);

    uniform_real_distribution<> distr(0.0, 1.0);

    double rand_prob = distr(gen);

    double randomValue;
    if (rand_prob <= 0.5) {
        randomValue = lower_bound + (midpoint - lower_bound) * sqrt(rand_prob / 0.5);
    }
    else {
        randomValue = midpoint + (upper_bound - midpoint) * sqrt((1.0 - rand_prob) / 0.5);
    }

    return randomValue;
}

int main()
{
    FastIO;

    vector<string> names = { "setosa","versicolor","virginica" };
    unordered_map<string, vector<vector<double>>> gyesu;
    gyesu[names[0]] = { { 4.4,5.5 },{ 2.9,4.2 },{ 1.0,1.7 },{ 0.1,0.5 } };
    gyesu[names[1]] = { { 4.9,7.0 },{ 2.3,3.2 },{ 3.3,5.1 },{ 1.0,1.8 } };
    gyesu[names[2]] = { { 4.9,7.7 },{ 2.5,3.8 },{ 4.8,6.4 },{ 1.6,2.5 } };

    for (string& name : names)
    {
        for (int i = 0; i < COUNT; i++)
        {
            double a = getRand(gyesu[name][0]);
            double b = getRand(gyesu[name][1]);
            double c = getRand(gyesu[name][2]);
            double d = getRand(gyesu[name][3]);

            printf("%.1lf,%.1lf,%.1lf,%.1lf,%s\n", a, b, c, d, name.c_str());
        }
    }
}