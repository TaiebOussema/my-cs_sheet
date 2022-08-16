#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// val      = 9
// binary   = 1 0 0 1

string toBinary(int val)
{
    int binary = 0;
    int iter = 1;
    int rem;
    while (val != 0)
    {
        rem = val % 2;
        val = val / 2;
        binary += rem * iter;
        iter *= 10;
    }
    return to_string(binary);
}

string toDecimal(int binaryVal)
{
    int temp = binaryVal;
    int position = 0;
    int result = 0;
    while (temp > 0)
    {
        int rightMostBit = temp % 10;
        result += rightMostBit * pow(2, position);
        position++;
        temp = temp / 10;
    }
    return to_string(result);
}

int main()
{
    int val = 465;
    int binVal = 100100111;
    cout << toBinary(val) << endl;
    cout << toDecimal(binVal) << endl;
    return 0;
}