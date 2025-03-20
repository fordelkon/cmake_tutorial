#include <iostream>
#include "MyInclude/aroundCenter.hpp"
using namespace std;


// 查找最长回文字符串
string longestPalindrome(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        pair<int, int> result = expandAroundCenter(s, i, i);
        int left1 = result.first;
        int right1 = result.second;
        result = expandAroundCenter(s, i, i + 1);
        int left2 = result.first;
        int right2 = result.second;
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}