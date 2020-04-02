#include "main.h"

int main() {
    File fil;
    if(loadCheckPoint(fil) != 1) {
        parseSTFile(fil);
        std::cout << std::endl << "Program ended success fully." << std::endl;
        return 0;
    }
    std::cout << "Closing the program because of an error" << std::endl;
    return 1;
}