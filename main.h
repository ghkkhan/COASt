#include <iostream>
#include <cstdlib>
#include <fstream>

int loadCheckPoint(std::ifstream &);
int parseSTFile(std::ifstream &);
std::string storyTag(std::fstream);
std::string spStoryTag(std::fstream);
std::string promptTag(std::fstream);
int saveCheckPoint();