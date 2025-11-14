#include "roof.h"

Roof::Roof(std::string factory_name) : Part(factory_name) {}

std::string Roof::GetInfo() const {
    return "[" + this->factory_name() + "]" + "Roof";
}
