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

double activationFct(double x)
{
    double result;
    result = 1/(1+exp(-x));
    return result;
}

double derivation(double x)
{
    double result;
    result = exp(-x)/((exp(-x)+1)*(exp(-x)+1));
    return result;
}

