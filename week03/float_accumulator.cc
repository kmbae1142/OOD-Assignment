#include "float_accumulator.h"


namespace float_accumulator {

Accumulator::Accumulator(float acc) : acc_(acc) { }

void Accumulator::Add(float num) {
    Accumulator::acc_ += num;
}

void Accumulator::Sub(float num) {
    Accumulator::acc_ -= num;
}

void Accumulator::Mul(float num) {
    Accumulator::acc_ *= num;
}

void Accumulator::Div(float num) {
    assert(num != 0.0 && "Divide by Zero");
    Accumulator::acc_ /= num;
}

float Accumulator::acc() const {
    return Accumulator::acc_;
}

} // float_accumulator
