#include "car.h"
#include "door.h"
#include "wheel.h"
#include "roof.h"

Car::Car(Part* door, Part* wheel, Part* roof, std::string color) : door_(door), wheel_(wheel), roof_(roof), color_(color) {}

Car::Car(const Car& car) : door_(nullptr), wheel_(nullptr), roof_(nullptr) {
    *this = car;
}

Car& Car::operator=(const Car& car) {
    if (this == &car) { return *this; }
    
    delete this->door_;
    delete this->wheel_;
    delete this->roof_;
    
    if (car.door_ != nullptr) {
        this->door_ = new Door(car.door_->factory_name());
    }
    if (car.wheel_ != nullptr) {
        this->wheel_ = new Wheel(car.wheel_->factory_name());
    }
    if (car.roof_ != nullptr) {
        this->roof_ = new Roof(car.roof_->factory_name());
    }

    this->color_ = car.color_;
    return *this;
}

Car::~Car() {
   delete this->door_;
   delete this->wheel_;
   delete this->roof_;
}

std::string Car::GetSpec() const {
    std::string result = "Car(";
    if (this->door_ != nullptr) { result += this->door_->GetInfo() + ','; } 
    if (this->wheel_ != nullptr) { result += this->wheel_->GetInfo() + ','; } 
    if (this->roof_ != nullptr) { result += this->roof_->GetInfo() + ','; } 
    result += this->color_ + ')';
    return result;
}


