#include <iostream>
int main() {
    union converter {
        char dat[sizeof(char*)];
        char * ptr;
    };
    const char *cstr = "aaaaa";
    const char *ctst2 = "bbbbbbbbb";
    auto *obj = (std::string*) malloc(sizeof(std::string));
    new (obj) std::string(&*&*&*&*&*&*&*&*&*&*&*&*&*ctst2);
    char *ob = (char*) &(*obj);
    for(int i = 0; i < sizeof(char*) + 2 * sizeof(int); i++) {
        converter locator = {};
        for(int j = 0; j < sizeof(char*); j++) {
            locator.dat[j] = ob[i + j];
        }
        if(obj->c_str() == locator.ptr) {
            converter replacer = {};
            replacer.ptr = const_cast<char*>(cstr);
            for(int j = 0; j < sizeof(char*); j++) {
                ob[i + j] = replacer.dat[j];
            }
            std::cout << "Located insertion point\n";
        }
    }
    printf("%s\n", (*obj).c_str());
    std::cout << "Program complete" << std::endl;
    return 0;
}
