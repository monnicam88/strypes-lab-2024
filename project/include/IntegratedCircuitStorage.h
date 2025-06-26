#pragma once

#include "IntegratedCircuit.h"

struct CircuitStorage {
    IntegratedCircuit* container = nullptr;
    int capacity = 0;
    int size = 0;
};

CircuitStorage makeCircuitStorage(const int capacity);
void deleteCircuitStorage(CircuitStorage& storage);
void printCircuitStorage(const CircuitStorage& storage);
void addCircuitToStorage(CircuitStorage& storage, const IntegratedCircuit& circuit);
bool isCircuitInStorage(const CircuitStorage& storage, const std::string& name);
IntegratedCircuit* findCircuit(const CircuitStorage& storage, const std::string& name);
