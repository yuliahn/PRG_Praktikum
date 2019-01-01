#include "neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(double x)
{
    this->value = x;
    this->activationOutput = 0;
    this->derivative = 0;
}

void Neuron::setValue(double x)
{
    this->value = x;
}

void Neuron::setActivation(double x)
{
    this->activationOutput = x;
}

void Neuron::setDerivation(double x)
{
    this->derivative = x;
}

double Neuron::getValue()
{
    return this->value;
}

double Neuron::getActivationOutput()
{
    return this->activationOutput;
}

double Neuron::getDerivative()
{
    return this->derivative;
}

