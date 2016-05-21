//#include <rapidjson/document.h>
//#include <rapidjson/rapidjson.h>
//#include <rapidjson/writer.h>
//#include <rapidjson/prettywriter.h>

#include <stdlib.h>
#include <iostream>
#include <string>

#include "server_Server.h"
#include "model/projectiles/server_Fire.h"
#include "model/projectiles/server_Spark.h"
#include "model/characters/mobs/server_Met.h"
#include "model/characters/humanoids/server_Bombman.h"
#include "model/characters/humanoids/server_Sparkman.h"
#include "model/obstacles/server_Needle.h"
#include "model/obstacles/server_Precipice.h"


int main(int argc, char *argv[]) {
	if (argc < 2)
		return EXIT_FAILURE;
    std::string port(argv[1]);

    std::cout << "Welcome to Megaman 3 Server Edition" << std::endl;




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

    return EXIT_SUCCESS;
}
