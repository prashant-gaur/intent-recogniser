#include "DiscoverIntention.h"
#include <iostream>
#include <regex>
#include <string>

DiscoverIntention::DiscoverIntention()
    : m_intention(Intention::NOT_SET)
{
    if (m_intentions_checklist.empty()) {
        m_intentions_checklist.push_back(&DiscoverIntention::check_for_weather_intention);
        m_intentions_checklist.push_back(&DiscoverIntention::check_for_calendar_intention);
        m_intentions_checklist.push_back(&DiscoverIntention::check_for_fact_intention);
    }
}

DiscoverIntention::~DiscoverIntention()
{
    //std::cout << "Destroy DiscoverIntention object \n";
    m_intentions_checklist.clear();
}

const std::string
DiscoverIntention::find_intention(const std::string& arg_user_input)
{
    // run through all available intentions
    bool found_intention = false;
    m_intention = Intention::NOT_SET; // reset intention

    for (auto checkintention : m_intentions_checklist) {
        found_intention = (this->*checkintention)(arg_user_input);
        if (found_intention)
            break;
    }

    if (m_intention != Intention::NOT_SET) {
        return enum_to_string(m_intention);
    }

    return "Actual intention could not be identified. Try again !!!";
}

bool DiscoverIntention::check_for_weather_intention(const std::string& arg_input_string)
{
    std::regex weather("(.*)(weather)(.*)");

    if (std::regex_match(arg_input_string, weather)) {
        //std::cout << "weather intention matched \n";
        m_intention = Intention::WEATHER;
        return true;
    }

    return false;
}

bool DiscoverIntention::check_for_calendar_intention(const std::string& arg_input_string)
{
    std::regex calendar("(.*)(\\d{1,2}[:]\\d{1,2})([ ]?)(pm|am|AM|PM)(.*)");

    if (std::regex_match(arg_input_string, calendar)) {
        //std::cout << "calendar intention matched \n";
        m_intention = Intention::CALENDAR;
        return true;
    }

    return false;
}

bool DiscoverIntention::check_for_fact_intention(const std::string& arg_input_string)
{
    std::regex fact("(.*)(fact[^ ]?)(.*)");

    if (std::regex_match(arg_input_string, fact)) {
        //std::cout << "fact intention matched \n";
        m_intention = Intention::FACT;
        return true;
    }

    return false;
}

const std::string
DiscoverIntention::enum_to_string(const Intention& value)
{
    switch (value) {
    case Intention::NOT_SET:
        return "Intention not found";
    case Intention::WEATHER:
        return "Get Weather";
    case Intention::CALENDAR:
        return "Check Calendar";
    case Intention::FACT:
        return "Get Fact";
    default:
        return "Invalid Intention";
    }
}