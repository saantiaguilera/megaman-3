#ifndef CLIENT_FIREMANVIEW_H_
#define CLIENT_FIREMANVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define FIREMAN_SPRITE_COUNT 12

class FiremanView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  FiremanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < FIREMAN_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_fireman/sprite_fireman" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~FiremanView() {
    SoundController::play(SDL2pp::Chunk("res/sound/deaths/boss.ogg"));
    for (int i = 0 ; i < FIREMAN_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    spriteStep();

    if (currentSprite > (FIREMAN_SPRITE_COUNT - 1))
      currentSprite = 0;

    return textureMap[currentSprite];
  }

};

#endif
