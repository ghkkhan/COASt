#include "main.h"

//parses the checkpoint file and opens the correct file.
int loadCheckPoint(std::ifstream &inFile) {
    inFile.open("./Files/checkPoint.st");
    if(!inFile) {
        std::cerr << "CheckPoint File does not exist or could not be loaded." << std::endl;
        return -1;
    }
    //read in the data in the check point file and return the "File-Name" to the main Program.
    std::string fileName;
    inFile >> fileName;
    fileName.pop_back();
    fileName.erase(0,1);
    std::cout << fileName << std::endl;
    inFile.close();
    inFile.open("./Files/" + fileName +".st");
    return 0;
}
//parses the file... main loop...
int parseSTFile(std::ifstream & srcFile) {
    std::bool sFlag = true;
    while(sFlag) {

    }
}
//parses the Story tag
std::string storyTag(std::ifstream & srcFile) {
    std::string nl;
    while(srcFile >> nl) {
        if(nl[0] == '<' && nl[1] =='!') {
            //This means we have a tag...check what tag it is.
            if(nl == "<!Story>") continue;//.....next line
            else if(nl == "<!wait>") {
                std::cout << "Press Enter to Continue...";
                std::cin >> nl;
            }
            else return nl; //sends the tag back to the main program, where it goes to its appropriate function
        }
        std::cout << nl << std::endl;
    }
}

