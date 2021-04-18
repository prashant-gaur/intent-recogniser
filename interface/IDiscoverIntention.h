#define pragma once

#include <string>

class IDiscoverIntention {
public:
    virtual ~IDiscoverIntention(){};
    virtual const std::string find_intention(const std::string& arg_user_input) = 0;
};
