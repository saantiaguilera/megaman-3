#ifndef CLIENT_BUMPYVIEW_H_
#define CLIENT_BUMPYVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define BUMPY_SPRITE_COUNT 4

#define FIRST_LEFT 2
#define LAST_LEFT 3
#define FIRST_RIGHT 0
#define LAST_RIGHT 1

class BumpyView : public AnimatedView {
private:
  ORIENTATION lastOrientation;

  std::map<int, SDL2pp::Texture*> textureMap;

public:
  BumpyView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < BUMPY_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_bumpy/sprite_bumpy" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~BumpyView() {
    SoundController::play(SDL2pp::Chunk("res/sound/deaths/mob.ogg"));
    for (int i = 0 ; i < BUMPY_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    //Seems bumpy wont move so it wil just do that
    spriteStep();

    if (currentSprite > LAST_LEFT)
      currentSprite = FIRST_LEFT;

    lastOrientation = orient;

    return textureMap[currentSprite];
  }

};

#endif
