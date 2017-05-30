#ifndef MEDANALYSIS_SERVER_ONECONTROLLER_H
#define MEDANALYSIS_SERVER_ONECONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include "../utils/utils.h"

using std::istream;
using std::string;
using std::vector;

class OneController {
public:

    vector<string> doOneEvaluation(vector<string> req,const string filePath);

};

#endif //MEDANALYSIS_SERVER_ONECONTROLLER_H
