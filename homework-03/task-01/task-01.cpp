#include <iostream>
#include <limits>
#include <numbers>

void setAttendance(uint64_t& attendanceMask, const int32_t studentId) {
    attendanceMask |= (1ULL << studentId);
}

void clearAttendance(uint64_t& attendanceMask, const int32_t studentId) {
    attendanceMask &= ~(1ULL << studentId);
}

void changeAttendance(uint64_t& attendanceMask, const int32_t studentId) {
    attendanceMask ^= (1ULL << studentId);
}

bool getAttendance(const uint64_t attendanceMask, const int32_t studentId) {
    return attendanceMask & (1ULL << studentId);
}

void printAttendanceInfo(const uint64_t attendanceMask) {
    std::cout << "Students present in class: ";
    for (int32_t id = 0; id < 64; id++) {
        if (getAttendance(attendanceMask, id))
            std::cout << id << " ";
    }

    std::cout << std::endl << "Students absent from class: ";
    for (int32_t id = 0; id < 64; id++) {
        if (!getAttendance(attendanceMask, id))
            std::cout << id << " ";
    }
    std::cout << std::endl << std::endl;
}

bool readInt32(std::istream& istream, int32_t& value) {
    if (istream >> value) 
        return true;
    else {
        istream.clear();
        istream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << std::endl << "Invalid input. Please enter an integer." 
                  << std::endl << "Try again." << std::endl;
    }
    return false;
}

bool isStudentIdValid(const int32_t studentId) {
    if (0 > studentId || 63 < studentId) {
        std::cerr << std::endl << "Invalid student id: " << studentId
                  << std::endl << "Valid id are between 0 and 63. Try again." << std::endl;
        return false;
    }
    return true;
}

int32_t main(void) {
    uint64_t attendance = 0;
    int32_t option = 0;

    std::cout << "[Welcome to CLASS ATTENDANCE program]" << std::endl << std::endl;

    while (1) {
        std::cout << "Choose among the following options:" << std::endl;
        std::cout << "1.Set attendance" << std::endl;
        std::cout << "2.Clear attendance" << std::endl;
        std::cout << "3.Attendance info" << std::endl;
        std::cout << "4.Change attendance" << std::endl;
        std::cout << "5.Exit" << std::endl;
        std::cout << "Option: ";

        if (!readInt32(std::cin, option)) {
            std::cout << std::endl;
            continue;
        }

        int32_t studentId = 0;
        switch (option) {
        case 1: {
            std::cout << "Set attendance for student with id [0, 63]: ";  
            if (readInt32(std::cin, studentId) && isStudentIdValid(studentId)) 
                setAttendance(attendance, studentId);
            std::cout << std::endl;
        } break;
        case 2: {
            std::cout << "Clear attendance for student with id [0, 63]: ";
            if (readInt32(std::cin, studentId) && isStudentIdValid(studentId))
                clearAttendance(attendance, studentId);
            std::cout << std::endl;
        } break;
        case 3: {
            std::cout << std::endl << "Students attendance info: " << std::endl;
            printAttendanceInfo(attendance);
        } break;
        case 4: {
            std::cout << "Change attendance for student with id [0, 63]: ";
            if (readInt32(std::cin, studentId) && isStudentIdValid(studentId)) 
                changeAttendance(attendance, studentId);
            std::cout << std::endl;
        } break;
        case 5:
            std::cout << std::endl << "Exit from the program requested. Have a nice day!" << std::endl;
            std::exit(EXIT_SUCCESS);
        default:
            std::cerr << std::endl << "Received unsupported option: " << option 
                      << std::endl << "Try again." << std::endl;
        }
    }

    return 0;
}
