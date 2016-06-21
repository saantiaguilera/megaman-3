#ifndef CLIENT_BOMBMAN_H_
#define CLIENT_BOMBMAN_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

#define BOMBMAN_SPRITE_COUNT 6

class BombmanView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  BombmanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < BOMBMAN_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_bombman/sprite_bombman" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~BombmanView() {
    SoundController::play(SDL2pp::Chunk("res/sound/deaths/boss.wav"));
    for (int i = 0 ; i < BOMBMAN_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    spriteStep();

    if (currentSprite > (BOMBMAN_SPRITE_COUNT - 1))
      currentSprite = 0;

    return textureMap[currentSprite];
  }

};

#endif
