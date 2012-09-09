#ifndef __UTILS__
#define __UTILS__

#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

#define stringify( name ) #name

#define NEWLINE "\n"
#define TAB     "\t"
#define SPACE   " "
#define COMMA   ","
#define COLON   ":"

const int WORD_SIZE = 4;
const int CHAR_SIZE = 1;
const int INT_SIZE  = 4;

// Use typeid too
std::string toString(ll n) {std::stringstream out(std::ios_base::out); out << n; return out.str();}

std::string pop(std::vector<std::string>& arr)
{
    std::string result = arr[arr.size() - 1];
    arr.pop_back();
    return result;
}

bool isInVector(const std::vector<std::string>& vec, std::string val)
{
    return (std::find(vec.begin(), vec.end(), val) != vec.end());
}

void eraseVectorElement(const std::vector<std::string>& vec, std::string val)
{
    std::vector<std::string>::iterator iter = std::find(vec.begin(), vec.end(), val);
    vec.erase(iter);
}

#endif