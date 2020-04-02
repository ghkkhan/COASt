#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct File {
    std::ifstream strim;
    std::string f_name;
};

int loadCheckPoint(File &);

int parseSTFile(File &);
int changeScript(File & , const std::string &);

std::string storyTag(File &);
std::string spStoryTag(File &, std::map<std::string, std::string> &);
std::vector<std::string> str_tokenize(const std::string &);
std::string str_SPModify(std::vector<std::string> &v, std::map<std::string, std::string> &);

std::string promptTag(File &, std::map<std::string, std::string> &);
int pInfo(std::ifstream &, std::map<std::string, std::string> &);
std::string pChoice( std::ifstream &);

int saveCheckPoint(const std::string &);
// void triggerEnd();