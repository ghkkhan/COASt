#include "main.h"

// parses the files... main loop...
int parseSTFile(File & srcFile) {

    std::map<std::string, std::string> vars; // vars stores the variables used in the script.
    std::string nl = "<!Story>";

    while(nl != "") {//nl works as a string holder and a flag simultaneously.
        if(nl == "error") {
            //if one of the functions below encounter an error that cannot be solved, 
            //they return a "error" string... basically, end the program.
            saveCheckPoint("Start");
            return 1;
        }
        if(nl == "<!Story>") nl = storyTag(srcFile);
        else if(nl == "<!Story_Spec>") nl = spStoryTag(srcFile, vars);
        else if(nl == "<!Prompt>") nl = promptTag(srcFile, vars);
        else if(nl == "<!CheckPoint>") nl = saveCheckPoint(nl);
    }
    saveCheckPoint("Start");
    return 0;
}