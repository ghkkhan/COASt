#include "main.h"

//parses the file... main loop...
int parseSTFile(std::ifstream & srcFile) {
    std::map<std::string, std::string> vars;

    std::string nl = "<!Story>";
    while(nl != "") { //nl works as a string holder and a flag simultaneously. 
        //the wiay to use these tags will be available in the documentation with great detail
        if(nl == "error") {
            saveCheckPoint("Start");
            return 1;
        }
        if(nl == "<!Story>") nl = storyTag(srcFile);
        else if(nl == "<!Story_Spec>") nl = spStoryTag(srcFile, vars);
        else if(nl == "<!Prompt>") nl = promptTag(srcFile, vars);
        // else if(nl == "<!CheckPoint>") saveCheckPoint(srcFile);
        // else if(nl == "") triggerEnd();

        /*
            @TODO
            Add more functions as nessesary to expand the program.
        */
    }
    saveCheckPoint("Start");
    return 0;
}
