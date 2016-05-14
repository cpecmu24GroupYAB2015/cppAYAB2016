#include <sstream>
#ifndef STRINOPERATOR_H
#define STRINGOPERATOR_H
template<typename T> inline std::string toString(T arg){
    std::ostringstream ss;
    ss << arg;
    return ss.str();
}

#endif // STRINOPERATOR_H
