#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Makes a string representation of an int vector
 * 
 * @param vect an int vector to be represented as a string
 * @return std::string a string representation of the int vector
 */
std::string intVectorToString(std::vector<int> vect) {
    std::string str;
    if(vect.begin() == vect.end()) {
        str = "()";
    } else {
        str = "(";
        for(std::vector<int>::iterator i = vect.begin(); i != vect.end(); ++i) {
            if(i == vect.end() - 1) {
                str += std::to_string(*i) + ")";
            } else {
                str += std::to_string(*i) + ", ";
            }
        }
    }
    return str;
}

int main() {
    std::vector<int> vect; //Initialize an empty vector to be used in the program.

    /**
     * List of all choices
     * 
     * -1: Exit
     *  0: Repeat options
     *  1: Display the current vector
     *  2: Add element to the front of the vector
     */
    int choice = 0;
    do {
        switch(choice) {
            case -1: {
                break;
            }

            case 0: {
                std::cout << "Please select one of the following: \n"
                          << "-1: Exit the program\n"
                          << "0: Show this menu\n"
                          << "1: Display the current vector\n"
                          << "2: Add element to the front of the vector\n"
                          << "Select: ";
                std::cin >> choice;
                break;
            }

            case 1: {
                std::cout << "The vector is currently: "
                          << intVectorToString(vect) << std::endl;
                choice = 0;
                break;
            }

            case 2: {
                std::cout << "What element to you want to add to the front of the vector? ";
                int temp;
                std::cin >> temp;
                vect.insert(vect.begin(), temp);
                choice = 0;
                break;
            }

            default: {
                std::cout << "Please enter a valid input." << std::endl;
                choice = 0;
                break;
            }
        }
    } while (choice != -1);

    return 0;
}