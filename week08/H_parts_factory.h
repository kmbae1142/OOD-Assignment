#ifndef _H_PARTS_FACTORY_H_
#define _H_PARTS_FACTORY_H_

#include "car_parts_factory.h"

class HPartsFactory : public CarPartsFactory {
    public:
        static HPartsFactory* GetInstance();
        Part* CreateDoor() const override;
        Part* CreateWheel() const override;
        Part* CreateRoof() const override;
    private:
        HPartsFactory();
        static HPartsFactory* instance_;
};                      

#endif // _H_PARTS_FACTORY_H_
