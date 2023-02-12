#include <GrEvents.h>

#include <iostream>
#include <map>
#include <string>
#include <vector>

typedef void (*func)(EventPacket&);
std::map<std::string, std::vector<func>> listeners;
void EventManager::signal(const char* EventType, EventPacket& ep) {
  std::vector<func>& eventHandler = listeners[EventType];
  for (func d : eventHandler) d(ep);
}

void EventManager::subscribeTo(const char* EventType, func fn) {
  std::vector<func>& eventHandler = listeners[EventType];
  eventHandler.push_back(fn);
}