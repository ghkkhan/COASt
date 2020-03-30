#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <map>

int loadCheckPoint(std::ifstream &);

int parseSTFile(std::ifstream &);
int changeScript(std::ifstream& , const std::string &);

std::string storyTag(std::ifstream &);
std::string spStoryTag(std::ifstream &, std::map<std::string, std::string> &);
std::vector<std::string> str_tokenize(const std::string &);
std::string str_SPModify(std::vector<std::string> &v, std::map<std::string, std::string> &);

std::string promptTag(std::ifstream &, std::map<std::string, std::string> &);
int pInfo(std::ifstream &, std::map<std::string, std::string> &);
std::string pChoice( std::ifstream &);

int saveCheckPoint(const std::string &);
// void triggerEnd();