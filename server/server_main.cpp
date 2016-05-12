#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "server_Server.h"

int main(int argc, char *argv[]) {
	if (argc < 2)
		return EXIT_FAILURE;
    std::string port(argv[1]);

    std::cout << "Welcome to Megaman 3 Server Edition" << std::endl;

    Server server = Server(port);
    server.run();

    return EXIT_SUCCESS;
}
