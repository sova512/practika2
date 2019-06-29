#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int RandomGenerate()
{
    static mt19937 rand((uint64_t)&rand);
    uniform_int_distribution<int> d(-1000000000, 1000000000);
    return d(rand);
}

int main()
{
    random_device rd;
    vector<int> v;
    mt19937 rand(-1000000000);
    steady_clock::time_point tp1 = steady_clock::now();
    for (int i=0; i < 10000000; i++)
        v.push_back(rand());
    steady_clock::time_point tp2 = steady_clock::now();
    duration<double> d = tp2 - tp1;
    cout << "Первый вектор: " << d.count() << " c." << endl;
    vector<int> v1(10000000);
    tp1 = steady_clock::now();
    generate(v1.begin(),v1.end(),RandomGenerate);
    tp2 = steady_clock::now();
    d = tp2 - tp1;
    cout << " Второй вектор: " << d.count() << " c." << endl;
    tp1 = steady_clock::now();
    vector<int> v2(v1);
    tp2 = steady_clock::now();
    cout << "Третий вектор: " << d.count() << " c." << endl;
    return 0;
}