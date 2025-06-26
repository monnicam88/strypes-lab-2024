# Digital Integrated Circuit Console Simulator
The entire source code of the project is available here in `project` folder, along with the `docs/documentation.pdf` file, which is the basic documentation of the project, describing the general functionalities and workflow of the application.

## 1. Project structure
```
project/
├── include/                                        # Header files (.h)
│   ├── Utils.h
│   ├── Constants.h
│   ├── TruthTable.h
│   ├── DataStructures.h
│   ├── MemoryManagement.h
│   ├── IntegratedCircuit.h
│   ├── IntegratedCircuitInput.h
│   ├── IntegratedCircuitStorage.h
│   └── LogicalExpressionHandler.h
├── src/                                            # Source files (.cpp)
│   ├── main.cpp
│   ├── TruthTable.cpp
│   ├── DataStructures.cpp
│   ├── IntegratedCircuit.cpp
│   ├── IntegratedCircuitInput.cpp
│   ├── IntegratedCircuitStorage.cpp
│   └── LogicalExpressionHandler.cpp
├── data/                                           # Test data (.txt)
│   ├── TruthTable1.txt
│   ├── TruthTable2.txt
│   ├── ...   
│   └── IntegratedCircuitsExamples.txt
│
└── README.md                                       # Project overview
```

**Explanation:**
- `include/` contains all header (.h) files that declare the interfaces and data structures.
- `src/` contains all source (.cpp) files that implement the logic for the modules.
- `data/` contains all text files (.txt) used for testing and examples.
- `README.md` documents the project.
  
## 2. Sample valid workflow of the project
      1) User interface
  ![1](https://github.com/user-attachments/assets/90a77478-47ce-4c07-9366-9ef5c780b6ca)

      2) DEFINE & RUN commands
  ![2](https://github.com/user-attachments/assets/7e3c0770-65ec-41ae-a9cb-a8cd889e36d3)

      3) ALL command
  ![3](https://github.com/user-attachments/assets/aca57c2f-78d1-4edc-8d10-c53ed66752b7)

      4) FIND command
  ![4](https://github.com/user-attachments/assets/7ee9c74b-316c-48ef-b03e-41946a616f53)

      5) PRINT & EXIT commands
  ![5](https://github.com/user-attachments/assets/cc0e0dcb-4445-4ab8-8486-c304622d5f3d)

## 3. Sample invalid workflow of the project
      1) User interface
  ![1](https://github.com/user-attachments/assets/f31abdfe-0bbe-42c6-8adf-03822c0b113e)

      2) DEFINE command invalid inputs
  ![6](https://github.com/user-attachments/assets/163e6f42-ddb2-40c1-824e-61002c2b1632)
      
      3) RUN command invalid inputs
  ![7](https://github.com/user-attachments/assets/79ed77af-ea70-457c-aaae-3abc0af7e488)

      4) FIND command invalid input
  ![8](https://github.com/user-attachments/assets/48211af8-595e-49ad-aa5f-3bf9b9fe3d11)
