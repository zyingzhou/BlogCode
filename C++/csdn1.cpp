/*
**
* Author: zhiying
* Date: 2023.6.9
*
* Description:
*/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    vector<char> chars;
    char ch;
    // 不忽略空白符
    while (cin >> noskipws >>ch){
        if ((int)ch ==10) break;
        chars.push_back(ch);
    }

    for (auto c:chars){
        cout <<c;
    }
    cout <<endl;

    return 0;
}
