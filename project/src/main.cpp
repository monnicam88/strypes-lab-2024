#include "IntegratedCircuitStorage.h"
#include "IntegratedCircuitInput.h"
#include "TruthTable.h"
#include "Utils.h"

int main() {  
    simulatorMenu();
    CircuitStorage storage = makeCircuitStorage(ProjectConstants::MAX_CIRCUITS);

    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream istream(input);
        std::string option;
        istream >> option;

        Commands command = getCommandEnum(option);
        switch (command) {
            case DEFINE: {
                IntegratedCircuit circuit = readIntegratedCircuit(istream);
                if (circuit.name.empty()) {
                    std::cerr << "Invalid expression entered. Skip DEFINE command."
                              << std::endl << "Enter a command: ";
                    deleteIntegratedCircuit(circuit);
                    continue;
                }
                if (isCircuitInStorage(storage, circuit.name))
                    std::cerr << "Digital Integrated Circuit '" << circuit.name << "' already exist. "
                    << "Instead, skip DEFINE command or create circuit with different name." << std::endl;   
                else addCircuitToStorage(storage, circuit);
                deleteIntegratedCircuit(circuit);
            } break;
            case RUN: {
                CircuitInput input = parseCommandRUN(istream);
                IntegratedCircuit* circuit = findCircuit(storage, input.circuitName);
                if (circuit) 
                    std::cout << "Result: " << executeCommandRUN(*circuit, input) << std::endl;
                else std::cerr << "Digital Integrated Circuit '" << input.circuitName << "' does NOT exist. "
                               << "Instead, skip RUN command or DEFINE the circuit." << std::endl;
                freeCircuitInputMemory(input);
            } break;
            case ALL: {
                std::string circuitName;
                istream >> circuitName;
                IntegratedCircuit* circuit = findCircuit(storage, circuitName);
                if (!circuit)
                    std::cerr << "Digital Integrated Circuit '" << circuitName << "' does NOT exist. "
                              << "Instead, skip ALL command or DEFINE the circuit." << std::endl;
                else executeCommandALL(*circuit);
            } break;
            case FIND: {
                const std::string fileName = getFileName(istream);
                TruthTable table = parseTruthTableFromFile(fileName);
                if (!table.data) {
                    std::cerr << "Skip FIND command." << std::endl << "Enter a command: ";
                    continue;
                }
                printTruthTable(table);

                std::cout << executeCommandFIND(table) << std::endl;
                deleteTruthTable(table);
            } break;
            case PRINT: {
                printCircuitStorage(storage);
            } break;
            case EXIT: return 0;
            default: std::cerr << "Invalid command. Please try again." << std::endl;
        }
        std::cout << std::endl << "Enter a command: ";
    }

    deleteCircuitStorage(storage);
    return 0;
}
