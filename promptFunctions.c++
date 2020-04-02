#include "main.h"

std::string promptTag(File & fil, std::map<std::string, std::string> &hsh) {
    std::string s;
    if(std::getline(fil.strim, s)) {
        if(s == "<!Prompt_Info>") {
            pInfo(fil.strim, hsh);
            return "<!Story>";
        }
        else if(s == "<!Prompt_Choice>") {
            s = pChoice(fil.strim, hsh);
            if(changeScript(fil, s) == 0) return "<!Story>";
        }
    }
    return "error";
}

int pInfo(std::ifstream &srcFile, std::map<std::string, std::string> & hsh) {
    std::string answer, s;
    if(std::getline(srcFile, s)) {
        if(s.find("<!Escape>") != std::string::npos) {
            pFormated(s, hsh);
        }
        else std::cout << s << std::endl;
        std::cout << "(Enter your response and press enter to continue) : ";
        std::getline(std::cin, answer);
        if(std::getline(srcFile, s)) {
            hsh.insert(std::pair<std::string, std::string>(s, answer));
            return 0;
        }
    }
    return 1;
}

std::string pChoice(std::ifstream & srcFile, std::map<std::string, std::string> & hsh) {
    std::string s;
    if(std::getline(srcFile, s)) {
        // TODO : Add a function that checks user_input for valid data.
        try {
            int num = std::stoi(s);
            std::string answer;
            std::vector<std::string> v(num);
            for(int i = 0; i < num; i++) {
                if(std::getline(srcFile, s)) {

                    if(s.find("<!Escape>") != std::string::npos) {
                        pFormated(s, hsh);
                    }
                    else std::cout << s << std::endl;
                    if(!(std::getline(srcFile, v[i]))) return "error";
                }
                else {
                    return "error";
                }
            }

            std::cout << "(Press a number and hit enter) : ";
            std::getline(std::cin, answer);
            num = std::stoi(answer);
            return v[num - 1];//returns a file name to be opened...
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
