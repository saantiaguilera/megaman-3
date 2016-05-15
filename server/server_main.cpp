//#include <rapidjson/document.h>
//#include <rapidjson/rapidjson.h>
//#include <rapidjson/writer.h>
//#include <rapidjson/prettywriter.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <glog/logging.h>

#include "server_Server.h"
#include "model/characters/humanoids/server_Bombman.h"
#include "model/characters/humanoids/server_Sparkman.h"
#include "model/characters/mobs/server_Met.h"

#define LOG_DEST "/var/tmp/fiuba-taller-I-megaman"

int main(int argc, char *argv[]) {
	if (argc < 2)
		return EXIT_FAILURE;
    std::string port(argv[1]);

    std::cout << "Welcome to Megaman 3 Server Edition" << std::endl;

    // Initialize Google's logging library.
    google::SetLogDestination(google::GLOG_INFO, LOG_DEST );
    google::InitGoogleLogging(argv[0]);

    LOG(INFO) << "Starting server...";

    Bombman aBombman;
    Sparkman aSparkman;
    aBombman.attack(&aSparkman);
    aSparkman.attack(&aBombman);
    std::cout << "Sparkman's health: " << aSparkman.getHp() << std::endl;
    std::cout << "Bombman's health: " << aBombman.getHp() << std::endl;
    Met met;
    aBombman.attack(&met);
    std::cout << "Met's health: " << met.getHp() << std::endl;




//    Server server = Server(port);
//    server.run();

    LOG(INFO) << "Quitting..";

    return EXIT_SUCCESS;
}
