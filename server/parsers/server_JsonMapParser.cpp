/*
 * server_JsonMapParser.cpp
 *
 *  Created on: Jun 4, 2016
 *      Author: mastanca
 */

#include "server_JsonMapParser.h"

#include <Common/b2Math.h>
#include <Dynamics/b2Body.h>
#include <vector>

#include "../../common/common_MapConstants.h"
#include "../../common/common_MapViewParser.h"
#include "../../common/rapidjson/document.h"
#include "../../common/rapidjson/rapidjson.h"
#include "../game_engine/server_Engine.h"
#include "../game_engine/server_EventContext.h"
#include "../game_engine/server_Player.h"
#include "../model/characters/humanoids/server_Bombman.h"
#include "../model/characters/humanoids/server_Fireman.h"
#include "../model/characters/humanoids/server_Magnetman.h"
#include "../model/characters/humanoids/server_Megaman.h"
#include "../model/characters/humanoids/server_Ringman.h"
#include "../model/characters/humanoids/server_Sparkman.h"
#include "../model/characters/mobs/server_Bumpy.h"
#include "../model/characters/mobs/server_JumpingSniper.h"
#include "../model/characters/mobs/server_Met.h"
#include "../model/characters/mobs/server_NormalSniper.h"
#include "../model/obstacles/server_Block.h"
#include "../model/obstacles/server_BossChamberGate.h"
#include "../model/obstacles/server_Ladder.h"
#include "../model/obstacles/server_Needle.h"
#include "../model/obstacles/server_Precipice.h"
#include "../model/powerups/server_BigAmmoPack.h"
#include "../model/powerups/server_BigEnergyCapsule.h"
#include "../model/powerups/server_Life.h"
#include "../model/powerups/server_SmallAmmoPack.h"
#include "../model/powerups/server_SmallEnergyCapsule.h"
#include "../serializers/server_ConnectedPlayerSerializer.h"
#include "../serializers/server_LifeChangeSerializer.h"
#include "../serializers/server_ObjectCreationSerializer.h"
#include "../services/server_CoordinatesConverter.h"


JsonMapParser::JsonMapParser() {
}

JsonMapParser::~JsonMapParser() {
}

void JsonMapParser::parseDocument(const std::string& name) {
	MapViewParser mapParser;
	rapidjson::Document* document = mapParser.serverMapFromPath(name);
	const rapidjson::Value& mapJson = (*document)[MAP_NAME];

	const rapidjson::Value& obstaclesJson = mapJson[MAPOBSTACLES_NAME];

	CoordinatesConverter converter;

	long int x, y;
	int type;
	float obstacleX, obstacleY;

	for (rapidjson::SizeType i = 0; i < obstaclesJson.Size(); i++) {
		x = obstaclesJson[i][X_NAME].GetUint();
		y = obstaclesJson[i][Y_NAME].GetUint();
		type = obstaclesJson[i][TYPE_NAME].GetInt();

		obstacleX = converter.pxToMeters(x);
		obstacleY = -converter.pxToMeters(y);

		inflateObject(type, obstacleX, obstacleY);
	}
}

void JsonMapParser::inflateObject(int type, float x, float y) {
	std::vector<Player*> playerList = Engine::getInstance().getPlayersList();
	ObjectCreationSerializer* renotifyMegamanSerializer = NULL;
	ConnectedPlayerSerializer* reconnectedPlayer = NULL;
	Powerup* powerup;
	switch (type) {
		case ObstacleViewTypeBlock:
			new Block(x, y);
			break;
		case ObstacleViewTypeBlock1:
			new Block(x, y);
			break;
		case ObstacleViewTypeBlock2:
			new Block(x, y);
			break;
		case ObstacleViewTypeBlock3:
			new Block(x, y);
			break;
		case ObstacleViewTypeBossChamberGate:
			new BossChamberGate(x, y);
			break;
		case ObstacleViewTypeLadder:
			new Ladder(x, y);
			break;
		case ObstacleViewTypeNeedle:
			new Needle(x, y);
			break;
		case ObstacleViewTypePrecipice:
			new Precipice(x, y);
			break;
		case ObstacleViewTypeBigAmmoPack:
			powerup = new BigAmmoPack(x, y);
			powerup->setBody();
			break;
		case ObstacleViewTypeBigEnergyCapsule:
			powerup= new BigEnergyCapsule(x, y);
			powerup->setBody();
			break;
		case ObstacleViewTypeLife:
			powerup = new Life(x, y);
			powerup->setBody();
			break;
		case ObstacleViewTypeSmallAmmoPack:
			powerup = new SmallAmmoPack(x, y);
			powerup->setBody();
			break;
		case ObstacleViewTypeSmallEnergyCapsule:
			powerup = new SmallEnergyCapsule(x, y);
			powerup->setBody();
			break;
		case ObstacleViewTypeBumpy:
			new Bumpy(x, y);
			break;
		case ObstacleViewTypeJumpingSnyper:
			new JumpingSniper(x, y);
			break;
		case ObstacleViewTypeMet:
			new Met(x, y);
			break;
		case ObstacleViewTypeNormalSnyper:
			new NormalSniper(x, y);
			break;
		case ObstacleViewTypeMegaman:
			if (playerList.at(0)->getMegaman() == NULL && !Engine::getInstance().isTeleportToBossChamberWasActivated()) {
				for (Player* aPlayer : playerList) {
					aPlayer->setMegaman(x, y);
				}
			} else {
				Megaman* megaman;
				for (Player* aPlayer : playerList) {
					megaman = aPlayer->getMegaman();
					if (megaman != NULL){
						megaman->getMyBody()->SetTransform(b2Vec2(x, y), 0);

						renotifyMegamanSerializer = new ObjectCreationSerializer(megaman);
						Engine::getInstance().getContext()->dispatchEvent(renotifyMegamanSerializer);

						reconnectedPlayer = new ConnectedPlayerSerializer(megaman);
						reconnectedPlayer->setDispatchClient(aPlayer->getId());
						Engine::getInstance().getContext()->dispatchEvent(reconnectedPlayer);

						LifeChangeSerializer* lifeChangeSerializer = new LifeChangeSerializer(
								megaman->getHumanOperator()->getLives());
						lifeChangeSerializer->setDispatchClient(megaman->getBoundId());
						Engine::getInstance().getContext()->dispatchEvent(lifeChangeSerializer);
					}
				}
			}
			break;
		case ObstacleViewTypeBombman:
			new Bombman(x, y);
			break;
		case ObstacleViewTypeFireman:
			new Fireman(x, y);
			break;
		case ObstacleViewTypeMagnetman:
			new MagnetMan(x, y);
			break;
		case ObstacleViewTypeRingman:
			new Ringman(x, y);
			break;
		case ObstacleViewTypeSparkman:
			new Sparkman(x, y);
			break;
		default:
			break;
	}
}
