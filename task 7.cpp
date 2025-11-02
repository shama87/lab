#include <iostream>
#include <string>

std::string createDisplayName(const std::string& partA, const std::string& partB) {

    std::string assembledName = partA + " " + partB;
    return assembledName;
}

int main() {

    const std::string userFirstName = "Shama";
    const std::string userLastName = "Zerin";


    std::cout << "Name Assembly Process" << std::endl;
    std::cout << "First piece being processed: " << userFirstName << std::endl;
    std::cout << "Second piece being processed: " << userLastName << std::endl;


    std::string completedName = createDisplayName(userFirstName, userLastName);


    std::cout << "\nOperation Complete. Final Full Name:" << std::endl;
    std::cout << ">> " << completedName << " <<" << std::endl;
    std::cout << "" << std::endl;

    return 0;
}
