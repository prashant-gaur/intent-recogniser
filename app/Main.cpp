#include "DiscoverIntention.h"
#include <cstring>
#include <iostream>
#include <memory>
#include <signal.h> // struct sigaction

static bool running = false;
static std::unique_ptr<DiscoverIntention> intentfinder(nullptr);

static void shutdown_handler(const int signo)
{
    switch (signo) {
    case SIGINT:
    case SIGTERM: {
        std::cout << "Quitting Application !!! \n";
        intentfinder.reset();
        break;
    }
    default:
        std::cout << "Signal not registered: " << signo << "\n";
    }

    exit(signo);
}

static bool setup_application()
{
    running = true;

    // setup discover intention service.
    intentfinder.reset(new DiscoverIntention);

    // register shutdown handler
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &shutdown_handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGTERM, &sa, NULL);

    return true;
}

static void start_application()
{
    std::string user_input;
    while (running) {
        std::cout << "Please ask your query ? \n";
        getline(std::cin, user_input);
        std::cout << "Your query is: " << user_input << "\n\n";
        if (intentfinder) {
            const std::string intention = intentfinder->find_intention(user_input);
            std::cout << "Your intention is: " << intention << "\n\n";
        }
    }
}

int main(int argc, char** argv)
{
    // setup application
    if (setup_application()) {
        std::cout << "Application setup sucessful. Start Application !!! \n";
        start_application();
    } else {
        std::cout << "Application setup failure. Exiting application !!! \n";
    }

    return 0;
}