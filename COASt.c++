#include "main.h"

int main() {
    std::ifstream fil;
    if(loadCheckPoint(fil) != 1) {
        std::string s;
        fil >> s;
        parseSTFile(fil, s);
    }
}
