#define pragma once

#include "IDiscoverIntention.h"
#include <functional>
#include <iostream>
#include <string>
#include <vector>

enum class Intention {
    NOT_SET,
    // list of available intentions
    WEATHER,
    CALENDAR,
    FACT
};

class DiscoverIntention : public IDiscoverIntention {
public:
    DiscoverIntention();
    virtual ~DiscoverIntention();
    // non-copyable
    DiscoverIntention(const DiscoverIntention& obj) = delete;
    DiscoverIntention& operator=(const DiscoverIntention& obj) = delete;

    const std::string find_intention(const std::string& arg_user_input) override;

private:
    bool check_for_weather_intention(const std::string& arg_input_string);
    bool check_for_calendar_intention(const std::string& arg_input_string);
    bool check_for_fact_intention(const std::string& arg_input_string);
    const std::string enum_to_string(const Intention& value);

    std::vector<bool (DiscoverIntention::*)(const std::string& arg_input_string)> m_intentions_checklist;
    Intention m_intention;
};
