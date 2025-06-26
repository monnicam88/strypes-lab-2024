#include <iostream>
#include <cmath>

bool isValidSixPointSystemGrade(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade) {
    const double MAX_SIX_POINT_SYSTEM_GRADE = 6.0;
    const double MIN_SIX_POINT_SYSTEM_GRADE = 2.0;

    return (firstGrade >= MIN_SIX_POINT_SYSTEM_GRADE && firstGrade <= MAX_SIX_POINT_SYSTEM_GRADE) &&
           (secondGrade >= MIN_SIX_POINT_SYSTEM_GRADE && secondGrade <= MAX_SIX_POINT_SYSTEM_GRADE) &&
           (thirdGrade >= MIN_SIX_POINT_SYSTEM_GRADE && thirdGrade <= MAX_SIX_POINT_SYSTEM_GRADE) &&
           (fourthGrade >= MIN_SIX_POINT_SYSTEM_GRADE && fourthGrade <= MAX_SIX_POINT_SYSTEM_GRADE);
}

int main() {
    double firstGrade = 0.0, secondGrade = 0.0, thirdGrade = 0.0, fourthGrade = 0.0;

    std::cout << "Enter four grades: ";
    std::cin >> firstGrade >> secondGrade >> thirdGrade >> fourthGrade;

    if (!isValidSixPointSystemGrade(firstGrade, secondGrade, thirdGrade, fourthGrade)) {
        std::cerr << "Error: All input values must be in range [2.0, 6.0]." << std::endl;
        return 1;
    }

    double result = firstGrade * secondGrade * thirdGrade * fourthGrade;
    double geometricMean = std::sqrt(result);

    std::cout << "Geometric mean of the grades is: " << geometricMean << std::endl;

    return 0;
}