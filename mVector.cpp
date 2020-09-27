#include "mVector.h"

vector<int> buildVector(string in)
{
    auto values = split(in.substr(1, in.length() - 2), ',');
    vector<int> vec;
    for (string s : values)
    {
        vec.push_back(parseInt(s));
    }
    return vec;
}

void printVector(vector<int> vec)
{
    cout << "(";
    if(vec.size()==0){
        return ;
    }
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        cout << "," << vec[i];
    }
    cout << ")" << endl;
}


void printVector(vector<bool> vec)
{
    cout << "(";
    if(vec.size()==0){
        return ;
    }
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        cout << "," << vec[i];
    }
    cout << ")" << endl;
}