#include <iostream>
#include <optional>
#include <vector>
#include <cstring>
#include "ConfigVariable.h"

using std::cout;

const ConfigFlag EXIST_MAX = ConfigFlag(EXISTS | MAX);

void reverse(char *str) {
    for(int i = 0; i < strlen(str) / 2; i++) {
        char sw = str[i];

    }
}

int main() {
    char *a = "1234";
//    ConfigVariable<int> a;
//
////    a.addFlag(EXISTS);
//    a.addFlag(MIN);
//    a.addFlag(MAX);
//    a.addFlag(AUTO);
//
//    cout << a.checkFlag(EXIST_MAX) << "\n";

//    std::vector<ConfigFlag> lst = {EXISTS, MAX, MIN, AUTO};
//    for(auto el : lst) {
//        cout << a.checkFlag(el) << "\n";
//    }


    return 0;
}