#include "H_parts_factory.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

HPartsFactory* HPartsFactory::instance_ = nullptr;

HPartsFactory::HPartsFactory() {}

HPartsFactory* HPartsFactory::GetInstance() {
    if (instance_ == nullptr) {
        instance_ = new HPartsFactory();
    }
    return instance_;
}

Part* HPartsFactory::CreateDoor() const {
    return new Door("H"); 
}

Part* HPartsFactory::CreateWheel() const {
    return new Wheel("H");
}

Part* HPartsFactory::CreateRoof() const {
    return new Roof("H");
}

