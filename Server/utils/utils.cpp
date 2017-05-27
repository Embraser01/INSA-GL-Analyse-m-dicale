#include "utils.h"

template<typename Out>
void split(const std::string &s, char delim, Out result, bool emptyString) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    if (emptyString) {
        while (std::getline(ss, item, delim)) {
            *(result++) = item;
        }
    } else {
        while (std::getline(ss, item, delim)) {
            if (!item.empty()) {
                *(result++) = item;
            }
        }
    }
}

std::vector<std::string> split(const std::string &s, char delim, bool emptyString) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems), emptyString);
    return elems;
}

std::vector<std::string> getError(std::string errorMsg) {

    std::vector<std::string> res;

    res.push_back("MA v1.0");
    res.push_back("ERROR " + errorMsg);
    res.push_back("");
    return res;
}

bool check_char_presence(std::vector<std::string> strings, const char *allowedChars) {

    for (auto it = strings.begin(); it != strings.end(); it++) {
        if (it->find_first_not_of(allowedChars) != std::string::npos) {
            return false;
        }
    }
    return true;
}

std::istream &safeGetline(std::istream &is, std::string &t) {
    t.clear();

    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.

    std::istream::sentry se(is, true);
    std::streambuf *sb = is.rdbuf();

    for (;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if (sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case EOF:
                // Also handle the case when the last line has no line ending
                if (t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char) c;
        }
    }
}