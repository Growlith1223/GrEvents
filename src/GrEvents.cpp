#include <GrEvents.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef void (*func)(EventPacket&);
std::map<std::string, std::vector<func>> listeners;
void EventManager::signal(const char* EventType, EventPacket& ep) {
    if (listeners.find(EventType) ==
        listeners
            .end()) {  // if not found, let user know that it does not exist.
        char* err = new char[256];
        sprintf(err, "Could not find '%s' within the available events.",
                EventType);
        throw new std::runtime_error(err);
    }
    std::vector<func>& eventHandler =
        listeners[EventType];  // Retrieve event listener
    for (func d : eventHandler)
        d(ep);  // for each observer attached, we signal to execute them.
}

void EventManager::subscribeTo(const char* EventType, func fn) {
    if (listeners.find(EventType) ==
        listeners.end()) {  // if not found, we create it
        listeners.emplace(std::pair<const char*, std::vector<func>>(
            EventType, std::vector<func>()));
    }
    std::vector<func>& eventHandler =
        listeners[EventType];    // Retrieve event listener
    eventHandler.push_back(fn);  // add observer to listener.
}