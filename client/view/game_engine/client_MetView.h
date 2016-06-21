#ifndef CLIENT_METVIEW_H_
#define CLIENT_METVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define MET_SPRITE_COUNT 3

#define SPRITE_MOVEMENT_FIRST 1
#define SPRITE_MOVEMENT_LAST 2
#define SPRITE_IDLE 0

class MetView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  MetView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < MET_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_met/sprite_met" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~MetView() {
    SoundController::play(SDL2pp::Chunk("res/sound/deaths/mob.ogg"));
    for (int i = 0 ; i < MET_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    switch (orient) {
      case UP:
      case DOWN:
      case IDLE:
        currentSprite = SPRITE_IDLE;
        break;
      case LEFT:
      case RIGHT:
        spriteStep();
        if (currentSprite > SPRITE_MOVEMENT_LAST)
          currentSprite = SPRITE_MOVEMENT_FIRST;
        break;
    }

    return textureMap[currentSprite];
  }

};

#endif
