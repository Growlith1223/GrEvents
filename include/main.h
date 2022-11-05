#include <map>
#include <vector>
#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
EXPORT std::map<int, std::vector<void*>> listeners;
namespace EventManager {
    /**
     * @brief Triggers every listener for a given event
     * @tparam EventType Event to trigger
     * @param args parameters to send to each listener
     */
    template <typename EventType, typename... Args>
    void signal(Args... args) {
        std::vector<void*>& eventHandler = listeners[EventType];
        for (void* d : eventHandler)
            reinterpret_cast<void (*)(Args...)>(d)(args...);
    }
    /**
     * @brief Attach function to event
     * @tparam EventType Event to listen to
     * @param func The function we want the EventManager to call
     */
    template <typename EventType, typename... Args>
    void subscribeTo(void (*func)(Args...)) {
        std::vector<void*>& eventHandler = listeners[EventType];
        eventHandler.push_back(reinterpret_cast<void*>(func));
    }
};