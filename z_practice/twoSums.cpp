/*

given a list of numbers and a target,
[3,6,9,12,15,7,8,4,2,1] ---- T=15
Output
(6,9)
(3,12)
(7,8)

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void displaySums(vector<int> V, int target)
{   
    vector<int> duplicate;
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V.size(); j++)
        {
            if ((V[i] + V[j] == target)) 
            {
                duplicate.push_back(V[i]);
                cout << "(" << V[i] << "," << V[j] << ")"
                     << endl;
                V[i] = target+1;
            }
        }
    }
}

int main()
{
    vector<int> test = {3, 6, 9, 12, 15, 7, 8, 4, 2, 1};
    for(int i=0; i<100; i++) {
        test.push_back(rand()%100);
    }
    int target = rand()%100 + 30;
    cout << target << endl;
    displaySums(test, target);
    return 0;
}