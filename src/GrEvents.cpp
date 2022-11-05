#include <GrEvents.h>
#include <iostream>
std::map<const char*, std::vector<void*>> listeners;

void EventManager::signal(const char* EventType, EventPacket* ep) {
        std::vector<void*>& eventHandler = listeners[EventType];
        for (void* d : eventHandler)
            reinterpret_cast<void (*)(EventPacket*)>(d)(ep);
    }

void EventManager::subscribeTo(const char* EventType, void(*func)(EventPacket*)) {
        std::vector<void*>& eventHandler = listeners[EventType];
        eventHandler.push_back(reinterpret_cast<void*>(func));
    }