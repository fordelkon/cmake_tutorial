#include <iostream>
#include "strUtils.hpp"
using namespace std;


int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Lack of raw string to find the longest palindrome!!!" << endl;
        return 1;
    }
    
    string str = argv[1];
    string res = longestPalindrome(str);
    cout << "The longest palindrome of `" << str << "` is `" << res << "`" << endl;
    return 0;
}