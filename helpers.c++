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
    std::map<std::string, std::string> vars;

    std::string nl = storyTag(srcFile);
    while(nl == "") {//nl works as a string holder and a flag simultaneously. 
        //the wiay to use these tags will be available in the documentation with great detail
        if(nl == "error") {
            return 1;
        }
        if(nl == "<!Story>") nl = storyTag(srcFile);
        else if(nl == "<!Story_Spec>") nl = spStoryTag(srcFile, vars);
        else if(nl == "<!Prompt>") nl = promptTag(srcFile, vars);
        else if(nl == "<!CheckPoint>") saveCheckPoint(srcFile);
        else if(nl == "") triggerEnd();
        /*
            @TODO
            Add more functions as nessesary to expand the program.
        */
    }
    return 0;
}

//parses the Story tag
std::string storyTag(std::ifstream & srcFile) {
    std::string nl;
    while(srcFile >> nl) {
        if(nl[0] == '<' && nl[1] =='!') {
            //This means we have a tag... let's check what tag it is.
            if(nl == "<!Story>") continue;//.....next line
            else if(nl == "<!wait>") {
                std::cout << "Press Enter to Continue...";
                std::cin >> nl;
                //check if player wants to quit the program.
                if(toLower(nl[0]) == 'q') return "";
            }
            else return nl; //sends the tag back to the parseSTFile function, where it goes to its appropriate function
        }
    }
    //this area should never really be executed...(error!)
    return "error";
}

std::string spStoryTag(std::ifstream & srcFile, std::map<std::string, std::string> hsh) {
    /*
        @TODO
        Add the rest of the content... decide how to do this part...
        ......
        for now, this function only supports the main character's name...
        pretty useless for now but its a start.
        uses a string to string map. 
        FINAL:: Template looks like this:
        <!Story_Spec>
        sentence sentence sentence <!Escape> keyword sentence sentence.
        This tag will be followed by a single line... if you need to do this with multiple lines, use the tag multiple times.
    */

    std::string nl;
    while(srcFile >> nl) {
        //used a while loop but it should only really work for a single line:
        //Will make it to work with multiple lines later....
        nl = str_tokenize(nl);
        std::cout << str_SPModify(nl) << std::endl;
        return srcFile >> nl;
    }
    return "error";
}

std::string str_tokenize(std::string & line) {

}

std::string str_SPModify(std::string & line) {

}

std::string promptTag(std::ifstream & srcFile) {
    /*
        @TODO
        get a number (number of choices )
        display to user the choices... get a number from the user...
        close current file and open the file chosen by the user.... 
    */
    return "";
    
}

int saveCheckPoint(std::ifstream & srcFile) {
    //save a string into the check point file?
    return 0;
}