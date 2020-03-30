#include "main.h"

int main() {
    std::ifstream fil;
    if(loadCheckPoint(fil) != 1) {
        parseSTFile(fil);
    }
}
