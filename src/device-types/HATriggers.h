#ifndef HATRIGGERS_H
#ifndef NO_HA_TRIGGERS
#define HATRIGGERS_H

#include "BaseDeviceType.h"

struct HATrigger {
    const char* type;
    const char* subtype;
} __attribute__((packed));

class HATriggers : public BaseDeviceType
{
public:
    HATriggers(HAMqtt& mqtt);
    virtual ~HATriggers();

    virtual void onMqttConnected() override;

    bool add(const char* type, const char* subtype);
    bool trigger(const char* type, const char* subtype);

protected:
    uint16_t calculateTopicLength(
        const char* component,
        HATrigger *trigger,
        const char* suffix,
        bool includeNullTerminator = true
    ) const;

    uint16_t generateTopic(
        char* output,
        const char* component,
        HATrigger *trigger,
        const char* suffix
    ) const;

private:
    uint16_t calculateSerializedLength(
        const HATrigger* trigger,
        const char* serializedDevice
    ) const;

    bool writeSerializedTrigger(
        const HATrigger* trigger,
        const char* serializedDevice
    ) const;

    HATrigger* _triggers;
    uint8_t _triggersNb;
};

#endif
#endif