//#include <rapidjson/document.h>
//#include <rapidjson/rapidjson.h>
//#include <rapidjson/writer.h>
//#include <rapidjson/prettywriter.h>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "server_Logger.h"
#include "server_Server.h"


int main(int argc, char *argv[]) {
	if (argc < 2)
		return EXIT_FAILURE;
    std::string port(argv[1]);

    std::cout << "Welcome to Megaman 3 Server Edition" << std::endl;

    Logger::getInstance().log(1, "Server starting...");


//    Fire aFire;
//    Spark aSpark;
//    Met met;
//    met.setVulnerable(false);
//    met.receiveShotFromProjectile(&aFire);
//    std::cout << "Met's health: " << met.getHp() << std::endl;
//    met.receiveShotFromProjectile(&aFire);
//    std::cout << "Met's health: " << met.getHp() << std::endl;
//    met.receiveShotFromProjectile(&aSpark);
//    std::cout << "Met's health: " << met.getHp() << std::endl;
//
//    Bombman aBombman;
//    Sparkman aSparkman;
//    Needle aNeedle;
//    Precipice aPrecipice;
//    std::cout << "Bombman's health: " << aBombman.getHp() << std::endl;
//    aNeedle.haveEffectOn(&aBombman);
//    std::cout << "Bombman's health: " << aBombman.getHp() << std::endl;
//    std::cout << "Sparkman's health: " << aSparkman.getHp() << std::endl;
//    aPrecipice.haveEffectOn(&aSparkman);
//    std::cout << "Sparkman's health: " << aSparkman.getHp() << std::endl;

//    aSparkman.getMyPoint().setX(1);
//    aSparkman.getMyPoint().setY(2);


    Server server = Server(port);
    server.run();

    Logger::getInstance().log(1, "Server quitting...");


    return EXIT_SUCCESS;
}
