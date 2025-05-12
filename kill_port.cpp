#include <cstdlib>
#include <iostream>
#include <string>

void killPort(int port) {
    std::string command = "fuser -k " + std::to_string(port) + "/tcp";
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Successfully killed processes using port " << port << std::endl;
    } else {
        std::cout << "Failed to kill port " << port << " or no process was using it." << std::endl;
    }
}

int main() {
    int port;
    std::cout << "Enter port to kill: ";
    std::cin >> port;
    killPort(port);
    return 0;
}
