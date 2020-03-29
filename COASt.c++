#include "main.h"

int main() {
    std::ifstream fil;
    loadCheckPoint(fil);
    parseSTFile(fil);
}
