#include <iostream>
#include <fstream>
#include <windows.h>

using std::string, std::ifstream, std::cout;

string getPath() {
    char a[100] = {0};
    GetModuleFileName(nullptr, a, 99);

    int end = strlen(a);
    for(char *ch = &a[end] - 1, slashCnt = 0; ch >= &a[0] && slashCnt != 2; ch--) {
        slashCnt += ch[0] == '\\';
        ch[1] = 0;
    }

    return a;
}

int main(int argc, char * argv[]) {
    cout << argv[0] << "\n";


    ifstream outfile;
    outfile.open(getPath() + "name.txt");
    int a;
    while (outfile >> a) {
        cout << a << "\n";
    }

    outfile.close();


//    union converter {
//        char dat[sizeof(char*)];
//        char * ptr;
//    };
//    const char *cstr = "aaaaa";
//    const char *ctst2 = "bbbbbbbbb";
//    auto *obj = (std::string*) malloc(sizeof(std::string));
//    new (obj) std::string(&*&*&*&*&*&*&*&*&*&*&*&*&*ctst2);
//    char *ob = (char*) &(*obj);
//    for(int i = 0; i < sizeof(char*) + 2 * sizeof(int); i++) {
//        converter locator = {};
//        for(int j = 0; j < sizeof(char*); j++) {
//            locator.dat[j] = ob[i + j];
//        }
//        if(obj->c_str() == locator.ptr) {
//            converter replacer = {};
//            replacer.ptr = const_cast<char*>(cstr);
//            for(int j = 0; j < sizeof(char*); j++) {
//                ob[i + j] = replacer.dat[j];
//            }
//            std::cout << "Located insertion point\n";
//        }
//    }
//    printf("%s\n", (*obj).c_str());
//    std::cout << "Program complete" << std::endl;
//    return 0;
}
