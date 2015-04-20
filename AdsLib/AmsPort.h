#ifndef _AMS_PORT_H_
#define _AMS_PORT_H_

#include "NotificationDispatcher.h"

#include <set>

using NotifyMapping = std::pair<uint32_t, std::shared_ptr<NotificationDispatcher> >;

struct AmsPort {
    AmsPort();
    void Close();
    bool IsOpen() const;
    uint16_t Open(uint16_t __port);
    uint32_t tmms;
    uint16_t port;

    void AddNotification(NotifyMapping mapping);
    bool DelNotification(const AmsAddr& ams, uint32_t hNotify);

private:
    static const uint32_t DEFAULT_TIMEOUT = 5000;
    std::set<NotifyMapping> notifications;
    std::mutex mutex;
};
#endif /* #ifndef _AMS_PORT_H_ */
