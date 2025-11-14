#include "K_parts_factory.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

KPartsFactory* KPartsFactory::instance_ = nullptr;

KPartsFactory::KPartsFactory() {}

KPartsFactory* KPartsFactory::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new KPartsFactory();
    }
    return instance_;
}

Part* KPartsFactory::CreateDoor() const {
    return new Door("K");
}

Part* KPartsFactory::CreateWheel() const {
    return new Wheel("K");
}

Part* KPartsFactory::CreateRoof() const {
    return new Roof("K");
}

