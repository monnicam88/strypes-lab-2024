#include <iostream>
#include <cassert>

static constexpr float PI = 3.141592653589793238f;

class VerticalCylinderVolumeCalculator {
private:
    float barrelRadius{};
    float barrelHeight{};
public:
    VerticalCylinderVolumeCalculator() = delete;

    VerticalCylinderVolumeCalculator(const float radius, const float height)
        : barrelRadius(radius), barrelHeight(height) {}

    float calcVolumeInCubicMeters() const {
        assert(barrelRadius > 0.f && barrelHeight > 0.f &&
            "Barrel radius and height must be positive numbers");
        return PI * (barrelRadius * barrelRadius) * barrelHeight;
    }

    float getRadius() const { 
        return barrelRadius; 
    }

    float getHeight() const { 
        return barrelHeight; 
    }
};

int main() {
    float barrelRadius = 0.f, barrelHeight = 0.f;

    std::cout << "Enter barrel radius in meters: ";
    std::cin >> barrelRadius;
    if (std::cin.fail()) {
        std::cerr << "Error: Program failed to read barrel radius" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter barrel height in meters: ";
    std::cin >> barrelHeight;
    if (std::cin.fail()) {
        std::cerr << "Error: Program failed to read barrel height" << std::endl;
        exit(EXIT_FAILURE);
    }

    VerticalCylinderVolumeCalculator calc(barrelRadius, barrelHeight);
    std::cout << "Volume of vertical cylinder is: " << calc.calcVolumeInCubicMeters() << " m^3" << std::endl;

    return 0;
}
