#include "IntegratedCircuitStorage.h"

CircuitStorage makeCircuitStorage(const int capacity) {
    CircuitStorage storage;
    storage.container = new IntegratedCircuit[capacity];
    storage.capacity = capacity;
    return storage;
}

void deleteCircuitStorage(CircuitStorage& storage) {
    for (int i = 0; i < storage.size; i++)
        deleteIntegratedCircuit(storage.container[i]);
 
    delete[] storage.container;
    storage.container = nullptr;
    storage.capacity = storage.size = 0;
}

void printCircuitStorage(const CircuitStorage& storage) {
    for (int i = 0; i < storage.size; i++) {
        std::cout << " " << i + 1 << ".";
        printIntegratedCircuit(storage.container[i]);
    }
}

void addCircuitToStorage(CircuitStorage& storage, const IntegratedCircuit& circuit) {
    assert(storage.size < storage.capacity && "Circuit storage capacity exceeded.");

    storage.container[storage.size] = createIntegratedCircuit();
    auto& storageCircuit = storage.container[storage.size];
    // Copy the arguments of the circuit
    for (int i = 0; i < circuit.arguments.length; i++) {
        const char currentArgument = circuit.arguments.data[i];
        addToCharArray(storageCircuit.arguments, currentArgument);
    }
    // Copy the logical expression
    for (int i = 0; i < circuit.tokenizedExpressions.length; i++) {
        const char currentToken = circuit.tokenizedExpressions.data[i];
        addToCharArray(storageCircuit.tokenizedExpressions, currentToken);
    }

    storageCircuit.name = circuit.name;
    storageCircuit.expression = circuit.expression;
    storage.size++;
}

bool isCircuitInStorage(const CircuitStorage& storage, const std::string& name) {
    for (int i = 0; i < storage.size; i++) {
        if (storage.container[i].name == name)
            return true;
    }
    return false;
}

IntegratedCircuit* findCircuit(const CircuitStorage& storage, const std::string& name) {
    for (int i = 0; i < storage.size; i++) {
        if (storage.container[i].name == name)
            return &storage.container[i];
    }
    return nullptr;
}
