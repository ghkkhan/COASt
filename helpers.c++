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
    inFile.close();
    return changeScript(inFile, fileName);
}

int changeScript(const std::ifstream & inFile, const std::string & newFileName) {
    saveCheckPoint(newFileName);
    inFile.open("./Files/" + newFileName +".st");
    if(!inFile) {
        std::cout << "Something went wrong while loading file." << std::endl;
        return 1;
    }
    return 0;
}

//parses the file... main loop...
int parseSTFile(std::ifstream & srcFile, nl) {
    std::map<std::string, std::string> vars;

    std::string nl = "<!Story>";
    while(nl != "") { //nl works as a string holder and a flag simultaneously. 
        //the wiay to use these tags will be available in the documentation with great detail
        if(nl == "error") {
            return 1;
        }
        if(nl == "<!Story>") nl = storyTag(srcFile);
        else if(nl == "<!Story_Spec>") nl = spStoryTag(srcFile, vars);
        else if(nl == "<!Prompt>") nl = promptTag(srcFile, vars);
        else if(nl == "<!CheckPoint>") saveCheckPoint(srcFile);
        // else if(nl == "") triggerEnd();

        /*
            @TODO
            Add more functions as nessesary to expand the program.
        */
    }
    return 0;
}

//parses the Story tag
std::string storyTag(const std::ifstream & srcFile) {
    std::string nl;
    while(srcFile >> nl) {
        if(nl[0] == '<' && nl[1] =='!') {
            //This means we have a tag... let's check what tag it is.
            if(nl == "<!Story>") continue;//.....next line
            else if(nl == "<!wait>") {
                std::cout << "(Press Enter to Continue...) ";
                std::cin >> nl;
                //check if player wants to quit the program.
                if(toLower(nl[0]) == 'q') return "";
            }
            else return nl; //sends the tag back to the parseSTFile function, where it goes to its appropriate function
        }
        else {
            // print story line
            std::cout << nl << std::endl;
        }
    }
    //this area should never really be executed...(error!)
    return "error";
}

std::string spStoryTag(const std::ifstream & srcFile,const std::map<std::string, std::string> &hsh) {
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
    if(srcFile >> nl) {
        //Will make it to work with multiple lines later....
        std::cout << str_SPModify(str_tokenize(nl), hsh) << std::endl;
        return "<!Story>";
    }
    return "error";
}

std::vector<std::string> str_tokenize(const std::string & line) {
    std::string temp = "";
    std::vector<std::string> v;
    for(int i = 0; i < line.size(); i++) {
        if(line[i] == " " && temp.size() != 0) {
            v.push_back(temp);
            temp = "";
        }
        else {
            if(line[i] != ' ') temp += line[i];
        }
    }
    v.push_back(temp);
    return v;
}

std::string str_SPModify(std::vector<std::string> &v, std::map<std::string, std::string> &hsh) {
    std::string retVar = "";
    for(int i = 0; i < v.size() - 1; i++) {
        if(v[i] == "<!Escape>") {
            i++;
            v[i] = hsh.find(v[i]) -> second;
        }
    }
    size_t t = v.size();
    for(int i = 0; i < t; i++) {
        if( v[i] == "<!Escape>" ) {
            v.erase(v.begin() + i);
            t--;
        }
        retVar+=v[i] + " ";
    }
    return retVar;
}

std::string promptTag(const std::ifstream &srcFile, std::map<std::string, std::string> &hsh) {
    /*
        @TODO
        Two prompt types::
        <!Prompt_Info>" && <!Prompt_Choice>
        prompt info prompts for information to store in a variable or something...
        prompt choice prompts user to make a choice and act on the choice.
        Here is the format::
    */
    std::string s;
    if(srcFile >> s) {
        if(s == "<!Prompt_Info>") {
            pInfo(srcFile, hsh);
            return "<!Story>";
        }
        else if(s == "<!Prompt_Choice>") {
            s = pChoice(srcFile);
            if(changeScript(srcFile, s) == 0) return "<!Story>" ;
        }
    }
    return "error";
}

int pInfo(const std::ifstream & srcFile, std::map<std::string, std::string> & hsh) {
    /*  Format::
    *****************
        Quesion quesion quesiton....?
        <!Prompt>
        <!Prompt_Info>
        Variable_Name (Key)...
    *****************
        The use will be prompted to answer the question and their answer will be reffererable using the Variable_Name ()...
        variable names are case-sensitive.....
    */
    std::string answer;
    if(srcFile >> s) {
        std::cout << s << std::endl << "(Enter your response and press enter to continue) : ";
        std::cin >> answer;
        if(srcFile >> s) {
            hsh.insert(std::pair<std::string, std::string>(s, answer));
            return 0;
        }
    }
    return 1;
}

std::string pChoice(const std::ifstream & srcFile) {
    /* Format
        2 (number of choices)
        1) choice choice choice 
        name of the file to go to... 
        2) choice choice choice
        name of the second file to go to...
    */
    if(srcFile >> s) {
        // s should be a number, ideally... if not, then not my problem...
        try {
            int num = std::stoi(s);
            std::string answer;
            std::vector<string> v(num);
            for(int i = 0; i < num; i++) {
                if(srcFile >> s) {
                    std::cout << s << std::endl;
                    if(!(srcFile >> v[i])) return 1;
                }
                else {
                    return "error";
                }
            }

            std::cout << "(Press a number and hit enter)";
            std::cin >> answer;//add a verifier so the valid number is entered.
            int num = std::stoi(answer);
            return v[answer];//returns a file name to be opened...
        }
        catch (std::invalid_argument const &err) {
            std::cerr << "The number of choices entered isn't valid." <<std::endl;
        }
        catch (std::out_of_range const &err) {
            std::cerr << "The number of choices entered is TOO BIG!" <<std::endl;
        }
    }
    return "error";
}

int saveCheckPoint(const std::string & s) {
    //save a string into the check point file?
    std::ofstream fil;
    fil.open("./Files/checkPoint.st");
    if(!fill) {
        std::cout << "Could not save..." << std::endl;
        return 1;
    };
    fil << s;
    return 0;
}