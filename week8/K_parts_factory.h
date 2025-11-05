#ifndef _K_PARTS_FACTORY_H_
#define _K_PARTS_FACTORY_H_

#include "car_parts_factory.h"

class KPartsFactory : public CarPartsFactory {
    public:
        static KPartsFactory* GetInstance();
        Part* CreateDoor() const override;
        Part* CreateWheel() const override;
        Part* CreateRoof() const override;
    private:
        KPartsFactory();
        static KPartsFactory* instance_;
};

#endif // _K_PARTS_FACTORY_H_
