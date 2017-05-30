#ifndef MEDANALYSIS_SERVER_UTILS_H
#define MEDANALYSIS_SERVER_UTILS_H

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

template<typename Out>
void split(const std::string &s, char delim, Out result, bool emptyString = true);

std::vector<std::string> split(const std::string &s, char delim, bool emptyString = true);

bool check_char_presence(std::vector<std::string> strings, const char *allowedChars);


std::vector<std::string> getError(std::string errorMsg);

std::istream &safeGetline(std::istream &is, std::string &t);

#endif //MEDANALYSIS_SERVER_UTILS_H
