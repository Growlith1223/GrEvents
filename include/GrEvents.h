#include <map>
#include <vector>
#include <tuple>

#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
class EventPacket {
	public:
	~EventPacket() {
		if (this)
			delete this;
	}
};
namespace EventManager {
    /**
     * @brief Triggers every listener for a given event
     * @tparam EventType Event to trigger
     * @param args parameters to send to each listener
     */
    EXPORT void signal(const char* EventType, EventPacket*);
    /**
     * @brief Attach function to event
     * @tparam EventType Event to listen to
     * @param func The function we want the EventManager to call
     */
    EXPORT void subscribeTo(const char* EventType, void(*func)(EventPacket*));
};