#include <iostream>
#include "print.h"

using namespace std;

void print(vector<string> output)
{
    for (int i = 0; i < output.size(); ++i)
    {
        cout << output[i] << endl;
    }
}
