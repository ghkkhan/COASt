#include "main.h"

//parses the Story tag
std::string storyTag(File & fil, std::map<std::string, std::string> &hsh) {
    std::string nl;
    while(std::getline(fil.strim, nl)) {
        if(nl.find("<!") != std::string::npos && nl.find("<!Escape>") == std::string::npos) {
            //This means we have a tag... let's check what tag it is.
            if(nl == "<!Story>") continue;//.....next line
            else if(nl == "<!Wait>") {
                std::cout << "(Press Enter to Continue...) ";
                std::cin >> nl;
                //check if player wants to quit the program.
                if(tolower(nl[0]) == 'q') return "";
            }
            else return nl; //sends the tag back to the parseSTFile function, where it goes to its appropriate function
        }
        else {
            // print story line...formated.
            if(nl.find("<!Escape>") == std::string::npos) {
                std::cout << nl << std::endl;
            }
            else {
                //this means there is atleast one escape tag in the line.
                pFormated(nl, hsh);
            }
        }
    }
    //this area should never really be executed...(error!)
    return "error";
}
int pFormated(std::string & nl, std::map<std::string, std::string> &hsh) {
    std::vector<std::string> vect = str_tokenize(nl);
    std::cout << str_SPModify(vect, hsh) << std::endl;
    return 0;
}

std::vector<std::string> str_tokenize(const std::string & line) {
    std::string temp = "";
    std::vector<std::string> v;
    for(unsigned long i = 0; i < line.size(); i++) {
        if(line[i] == ' ' && temp.size() != 0) {
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
    for(unsigned long i = 0; i < v.size() - 1; i++) {
        if(v[i] == "<!Escape>") {
            i++;
            v[i] = hsh.find(v[i]) -> second;
        }
    }
    size_t t = v.size();
    for(unsigned long i = 0; i < t; i++) {
        if( v[i] == "<!Escape>" ) {
            v.erase(v.begin() + i);
            t--;
        }
        retVar+=v[i] + " ";
    }
    return retVar;
}
