#include "main.h"
std::string promptTag(std::ifstream &srcFile, std::map<std::string, std::string> &hsh) {
    /*
        @TODO
        Two prompt types::
        <!Prompt_Info>" && <!Prompt_Choice>
        prompt info prompts for information to store in a variable or something...
        prompt choice prompts user to make a choice and act on the choice.
        Here is the format::
    */
    std::string s;
    if(std::getline(srcFile, s)) {
        if(s == "<!Prompt_Info>") {
            pInfo(srcFile, hsh);
            return "<!Story>";
        }
        else if(s == "<!Prompt_Choice>") {
            s = pChoice(srcFile);
            std::cout << s << std::endl;
            // std::cout << std::endl<< std::endl<< std::endl<< std::endl<< std::endl;
            if(changeScript(srcFile, s) == 0) return "<!Story>" ;
        }
    }
    return "error";
}

int pInfo(std::ifstream & srcFile, std::map<std::string, std::string> & hsh) {
    /*  Format::
    *****************
        <!Prompt>
        <!Prompt_Info>
        Quesion quesion quesiton....?
        Variable_Name (Key)...
    *****************
        The use will be prompted to answer the question and their answer will be reffererable using the Variable_Name ()...
        variable names are case-sensitive.....
    */
    std::string answer, s;
    if(std::getline(srcFile, s)) {
        std::cout << s << std::endl << "(Enter your response and press enter to continue) : ";
        std::getline(std::cin, answer);
        if(std::getline(srcFile, s)) {
            hsh.insert(std::pair<std::string, std::string>(s, answer));
            return 0;
        }
    }
    return 1;
}

std::string pChoice(std::ifstream & srcFile) {
    /* Format
        2 (number of choices)
        1) choice choice choice 
        name of the file to go to... 
        2) choice choice choice
        name of the second file to go to...
    */
    std::string s;
    if(std::getline(srcFile, s)) {
        // s should be a number, ideally... if not, then not my problem...
        try {
            int num = std::stoi(s);
            std::string answer;
            std::vector<std::string> v(num);
            for(int i = 0; i < num; i++) {
                if(std::getline(srcFile, s)) {
                    std::cout << s << std::endl;
                    if(!(std::getline(srcFile, v[i]))) return "error";
                }
                else {
                    return "error";
                }
            }

            std::cout << "(Press a number and hit enter)";
            std::getline(std::cin, answer);
            num = std::stoi(answer);
            return v[num - 1];//returns a file name to be opened...
        }
        catch(std::bad_alloc & exception) {
            std::cerr << "Bad Aloc, bruda" <<std::endl;
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
