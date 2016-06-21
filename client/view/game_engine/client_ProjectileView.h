#ifndef CLIENT_PROJECTILEVIEW_H_
#define CLIENT_PROJECTILEVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define SPRITE_COUNT 4

#define SPRITE_COUNT_EXTENDED 8

#define IDLE_POSITION -1
#define IDLE_PATH "res/drawable/bullets/idle.png"

class ProjectileView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;
  int firstLeft, firstRight, size, counter;

  int projectileType;
  ORIENTATION lastOrientation;

public:
  ProjectileView(unsigned int id, int type, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    std::string path = "res/drawable/bullets/";
    projectileType = type;
    size = SPRITE_COUNT;

    lastOrientation = IDLE;
    counter = 0;

    switch (type) {
      case ObstacleViewTypeBomb:
        path += "bombman/";
        SoundController::play(("./res/sound/bullets/create/bomb.wav"));
        break;
      case ObstacleViewTypeFire:
        path += "fireman/";
        size = SPRITE_COUNT_EXTENDED;
        SoundController::play(("res/sound/bullets/create/fire.wav"));
        break;
      case ObstacleViewTypeMagnet:
        path += "magnetman/";
        size = SPRITE_COUNT_EXTENDED;
        SoundController::play(("res/sound/bullets/create/magnet.wav"));
        break;
      case ObstacleViewTypeRing:
        path += "ringman/";
        SoundController::play(("res/sound/bullets/create/ring.wav"));
        break;
      case ObstacleViewTypeSpark:
        path += "sparkman/";
        SoundController::play(("res/sound/bullets/create/spark.wav"));
        break;
      case ObstacleViewTypePlasma:
        path += "normals/";
        size = SPRITE_COUNT_EXTENDED;
        SoundController::play(("res/sound/bullets/create/normal.wav"));
        break;
    }

    path += "bullet";

    if (size == SPRITE_COUNT) {
      firstLeft = 1;
      firstRight = 1;
    }

    if (size == SPRITE_COUNT_EXTENDED) {
      firstRight = 1;
      firstLeft = 5;
    }

    for (int i = 0 ; i < size ; ++i) {
      std::stringstream ss;
      ss << path << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }

    textureMap[IDLE_POSITION] = new SDL2pp::Texture(*getRenderer(), IDLE_PATH);
  }

  virtual ~ProjectileView() {
    switch (projectileType) {
      case ObstacleViewTypeBomb:
        SoundController::play(("res/sound/bullets/destroy/bomb.wav"));
        break;
      case ObstacleViewTypeFire:
        SoundController::play(("res/sound/bullets/destroy/fire.wav"));
        break;
      case ObstacleViewTypeMagnet:
        SoundController::play(("res/sound/bullets/destroy/magnet.wav"));
        break;
      case ObstacleViewTypeRing:
        SoundController::play(("res/sound/bullets/destroy/ring.wav"));
        break;
      case ObstacleViewTypeSpark:
        SoundController::play(("res/sound/bullets/destroy/spark.wav"));
        break;
      case ObstacleViewTypePlasma:
        SoundController::play(("res/sound/bullets/destroy/normal.wav"));
        break;
    }

    for (int i = 0 ; i < size ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    if (orient == lastOrientation) {
      counter++;
      switch (orient) {
        case UP:
        case DOWN:
        case IDLE:
          currentSprite = IDLE_POSITION;
          break;
        case LEFT:
          spriteStep();
          if (counter > SPRITE_COUNT) {
            currentSprite = firstLeft;
            counter = 0;
          }
          break;
        case RIGHT:
          spriteStep();
          if (counter > SPRITE_COUNT) {
            currentSprite = firstRight;
            counter = 0;
          }
          break;
      }
    } else {
      counter = 0;
      switch (orient) {
        case UP:
        case DOWN:
        case IDLE:
          break;
        case LEFT:
          currentSprite = firstLeft;
          break;
        case RIGHT:
          currentSprite = firstRight;
          break;
      }
    }

    lastOrientation = orient;

    return textureMap[currentSprite];
  }

};

#endif
