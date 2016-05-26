//#include <rapidjson/document.h>
//#include <rapidjson/filereadstream.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <string>

#include "game_engine/server_Player.h"
#include "server_Logger.h"
#include "server_Server.h"

#include <Box2D/Box2D.h>

int main(int argc, char *argv[]) {
	if (argc < 2)
		return EXIT_FAILURE;
    std::string port(argv[1]);

    std::cout << "Welcome to Megaman 3 Server Edition" << std::endl;

    Logger::getInstance().log(1, "Server starting...");

//    std::string filename = "./json/basicMap.json";
//    FILE* pFile = fopen(filename.c_str(), "rb");
//    char buffer[65536];
//    rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
//    rapidjson::Document document;
//    document.ParseStream<rapidjson::FileReadStream>(is);

//    std::cout << document["map"].GetInt() << std::endl;
//    const rapidjson::Value& a = document["response"];
//    for (rapidjson::Value::ConstValueIterator itr = a.Begin(); itr != a.End(); ++itr)
//        std::cout << itr->GetObject()["id"].GetInt() << std::endl;
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
