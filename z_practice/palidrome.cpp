#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string word)
{
    for (int i = 0; i < word.size() / 2; i++)
    {
        for (int j = word.size() - 1; j > word.size() / 2; j--)
        {
            if (word[i] != word[j])
            {
                cout << "False" << endl;
                return false;
            }
        }
    }
    cout << "True" << endl;
    return true;
}

int main()
{
    // cout << checkPalindrome("aabaa") << endl;
    // cout << checkPalindrome("aaaaa") << endl;
    checkPalindrome("aaaaaaaaaaaaaXaaaaaaaaaaaaa");
    checkPalindrome("xaabaa");
    return 0;
}