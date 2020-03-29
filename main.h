#include <iostream>
#include <cstdlib>
#include <fstream>

int loadCheckPoint(std::ifstream &);
int parseSTFile(std::ifstream &);
int changeScript(std::ifstream& , const std::string &)
std::string storyTag(const std::ifstream &);
std::string str_SPModify(const std::string &);

std::string spStoryTag(const std::ifstream &,const std::map<std::string, std::string> &);
std::string str_tokenize(std::string &);
std::string promptTag(const std::ifstream &, std::map<std::string, std::string> &);
int saveCheckPoint(std::ifstream &);
void triggerEnd();