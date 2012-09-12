#ifndef __UTILS__
#define __UTILS__

#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>

#define stringify( name ) #name

#define NEWLINE "\n"
#define TAB     "\t"
#define SPACE   " "
#define COLON   ":"

const int WORD_SIZE = 4;
const int CHAR_SIZE = 1;
const int INT_SIZE  = 4;

typedef long long ll;

// Use typeid too
std::string toString(ll n);

template <typename T>
bool isInVector(const std::vector<T>& vec, T val)
{
    return (std::find(vec.begin(), vec.end(), val) != vec.end());
}

template <typename T>
void eraseVectorElement(std::vector<T>& vec, T val)
{
    vec.erase( std::remove( vec.begin(), vec.end(), val), vec.end() );
}

#endif