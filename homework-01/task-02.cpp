#include <iostream>
#include <cassert>
#include <cmath>

class BodyMassIndexCalculator {
private:
    float bodyMass{};
    float bodyHeight{};
public:
    BodyMassIndexCalculator() = delete;

    BodyMassIndexCalculator(const float mass, const float height)
        : bodyMass(mass), bodyHeight(height) {}

    float calcLowPrecisionBMI() const {
        assert(bodyMass > 0.0f && "Body mass must be positive number");
        assert(bodyHeight > 0.0f && "Body height must be positive number");
        return bodyMass / std::pow(bodyHeight, 2.f);
    }

    float calcHighPrecisionBMI() const {
        assert(bodyMass > 0.0f && "Body mass must be positive number");
        assert(bodyHeight > 0.0f && "Body height must be positive number");
        return 1.3f * (bodyMass / std::pow(bodyHeight, 2.5f));
    }

    float getBodyMass() const { 
        return bodyMass; 
    }

    float getBodyHeight() const { 
        return bodyHeight; 
    }
};

int main() {
    float mass = 0.0f, height = 0.0;

    std::cout << "Enter body mass in kg: ";
    std::cin >> mass;
    if (std::cin.fail()) {
        std::cerr << "Error: Program failed to read body mass" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter body height in meters: ";
    std::cin >> height;
    if (std::cin.fail()) {
        std::cerr << "Error: Program failed to read body height" << std::endl;
        exit(EXIT_FAILURE);
    }

    BodyMassIndexCalculator bmiCalc(mass, height);

    std::cout << "Your low precision BMI is: " << bmiCalc.calcLowPrecisionBMI() << std::endl;
    std::cout << "Your high precision BMI is: " << bmiCalc.calcHighPrecisionBMI() << std::endl;

    return 0;
}
