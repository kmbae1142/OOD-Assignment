#ifndef _CAR_BUILDER_H_
#define _CAR_BUILDER_H_

#include "car_parts_factory.h"
#include "car.h"

class CarBuilder {
    public:
        explicit CarBuilder(const CarPartsFactory* factory);
        CarBuilder& CreateDoor();
        CarBuilder& CreateWheel();
        CarBuilder& CreateRoof();
        CarBuilder& SetColor(std::string color);
        Car* Build();
    private:
        Part* door_;
        Part* wheel_;
        Part* roof_;
        std::string color_;
        const CarPartsFactory* factory_;
};

#endif
