#include <utils.h>

std::string toString(ll n) 
{
    std::stringstream out(std::ios_base::out); out << n; return out.str();
}