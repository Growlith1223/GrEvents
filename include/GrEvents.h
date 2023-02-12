#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#ifndef H_GREVENTS_H
#define H_GREVENTS_H
class EventPacket {
   public:
    ~EventPacket() {
    }
};
namespace EventManager {
    /**
     * @brief Triggers every listener for a given event
     * @param EventType Name of Event to trigger
     * @param packet parameters to send to each listener packed into a packet
     * for ease of use
     */
    EXPORT void signal(const char* EventType, EventPacket& packet);
    /**
     * @brief Attach function to event
     * @param EventType Name of Event to listen to
     * @param func The function we want the EventManager to call
     */
    EXPORT void subscribeTo(const char* EventType, void (*func)(EventPacket&));
};  // namespace EventManager
#endif