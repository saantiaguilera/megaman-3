#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>

#include "parsers/server_ConfigParser.h"
#include "server_Logger.h"
#include "server_Server.h"

int main(int argc, char *argv[]) {
	if (argc < 3)
		return EXIT_FAILURE;
    std::string port(argv[1]);
    std::string configFilename(argv[2]);

    std::cout << "Welcome to Megaman 3 Server Edition" << std::endl;

    // Seed rand
    srand(time(NULL));

    Logger::getInstance().log(1, "Server starting...");

    ConfigParser configParser(configFilename);
    configParser.parseConfigDoc();

    Server server = Server(port);
    server.run();

    Logger::getInstance().log(1, "Server quitting...");

    return EXIT_SUCCESS;
}
