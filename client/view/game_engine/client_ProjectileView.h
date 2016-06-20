#ifndef CLIENT_PROJECTILEVIEW_H_
#define CLIENT_PROJECTILEVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

#define SPRITE_COUNT 4

#define SPRITE_COUNT_EXTENDED 8

#define IDLE_POSITION -1
#define IDLE_PATH "res/drawable/bullets/idle.png"

class ProjectileView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;
  int firstLeft, firstRight, size, counter;

  ORIENTATION lastOrientation;

public:
  ProjectileView(unsigned int id, int type, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    std::string path = "res/drawable/bullets/";
    size = SPRITE_COUNT;

    lastOrientation = IDLE;
    counter = 0;

    switch (type) {
      case ObstacleViewTypeBomb:
        path += "bombman/";
        break;
      case ObstacleViewTypeFire:
        path += "fireman/";
        size = SPRITE_COUNT_EXTENDED;
        break;
      case ObstacleViewTypeMagnet:
        path += "magnetman/";
        size = SPRITE_COUNT_EXTENDED;
        break;
      case ObstacleViewTypeRing:
        path += "ringman/";
        break;
      case ObstacleViewTypeSpark:
        path += "sparkman/";
        break;
      case ObstacleViewTypePlasma:
        path += "normals/";
        size = SPRITE_COUNT_EXTENDED;
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
