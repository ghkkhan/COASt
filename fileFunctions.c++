#include "main.h"

//parses the checkpoint file and opens the correct file.
int loadCheckPoint(std::ifstream &inFile) {
    inFile.open("./Files/checkPoint.st");
    if(!inFile) {
        std::cerr << "CheckPoint File does not exist or could not be loaded." << std::endl;
        return 1;
    }
    //read in the data in the check point file and return the "File-Name" to the main Program.
    std::string fileName;
    inFile >> fileName;
    fileName.pop_back();
    fileName.erase(0,1);
    return changeScript(inFile, fileName);
}

int changeScript(std::ifstream & inFile, const std::string & newFileName) {
    saveCheckPoint(newFileName);
    inFile.close();
    inFile.open("./Files/" + newFileName +".st");
    if(!inFile) {
        std::cout << "Something went wrong while loading file." << std::endl;
        return 1;
    }
    return 0;
}

int saveCheckPoint(const std::string & s) {
    //save a string into the check point file?
    std::ofstream fil;
    fil.open("./Files/checkPoint.st");
    if(!fil) {
        std::cout << "Could not save..." << std::endl;
        return 1;
    };
    if(s != "error") fil <<'/' << s << '/';
    return 0;
}