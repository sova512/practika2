#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

int RandomGenerate()
{
    static mt19937 rand((uint64_t)&rand);
    uniform_int_distribution<int> d(-1000000000, 1000000000);
    return d(rand);
}

int main()
{
    vector<int> v;
    mt19937 rand(-1000000000);
    for (int i=0; i < 10000000; i++)
        v.push_back(rand());
    vector<int> v1(10000000);
    generate(v1.begin(),v1.end(),RandomGenerate);
    vector<int> v2(v1);
    for(auto e:v2)
        cout<<e<<'\t';
    cout<<endl;
    return 0;
}