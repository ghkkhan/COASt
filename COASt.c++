#include "main.h"

int main() {
    std::ifstream fil;
    if(loadCheckPoint(fil) != 1) {
        parseSTFile(fil);
        std::cout << "Program ended success fully." << std::endl;
    }
}
