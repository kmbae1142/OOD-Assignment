#include "int_accumulator.h"


namespace int_accumulator {

Accumulator::Accumulator(int acc) : acc_(acc) { }

void Accumulator::Add(int num) {
    Accumulator::acc_ += num;
}

void Accumulator::Sub(int num) {    
    Accumulator::acc_ -= num;
}

void Accumulator::Mul(int num) {    
    Accumulator::acc_ *= num;
}

void Accumulator::Div(int num) {
    assert(num != 0 && "Divide by Zero");
    Accumulator::acc_ /= num;
}

int Accumulator::acc() const {
    return Accumulator::acc_;
}

}  // namespace int_accumulator
