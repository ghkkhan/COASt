#include "main.h"

//parses the checkpoint file and opens the correct file.
int loadCheckPoint(File & srcFile) {

    if(changeScript(srcFile, "checkPoint") == 0) {
        std::string fileName;
        srcFile.strim >> fileName;
        fileName.pop_back();
        fileName.erase(0,1);
        return changeScript(srcFile, fileName);
    }
    return 1;
}
int saveCheckPoint(const std::string & s) {
    if(s == "error") return 1;
    std::ofstream fil;
    fil.open("./Files/checkPoint.st");
    if(!fil) {
        std::cout << "Something went wrong while loading file." << std::endl;
        return 1;
    }
    fil << '/' << s << '/';
    return 0;
}

int changeScript(File & srcFile, const std::string & newFileName) {
    if(srcFile.strim.is_open()) srcFile.strim.close();
    srcFile.strim.open("./Files/" + newFileName +".st");
    if(!srcFile.strim) {
        std::cout << "Something went wrong while loading file." << std::endl;
        return 1;
    }
    srcFile.f_name = newFileName;
    return 0;
}