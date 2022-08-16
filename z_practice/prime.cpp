#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPrime(int val)
{
    for(int i=2; i<val/2; i++){
        if((val%i) == 0) {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    int val = 10;
    if(isPrime(val)) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime !" << endl;
    }
    return 0;
}