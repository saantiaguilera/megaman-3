#ifndef CLIENT_MAGNETMANVIEW_H_
#define CLIENT_MAGNETMANVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define MAGNETMAN_SPRITE_COUNT 9

class MagnetmanView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  MagnetmanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < MAGNETMAN_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_magnetman/sprite_magnetman" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~MagnetmanView() {
    SoundController::play(("res/sound/deaths/boss.wav"));
    for (int i = 0 ; i < MAGNETMAN_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    spriteStep();

    if (currentSprite > (MAGNETMAN_SPRITE_COUNT - 1))
      currentSprite = 0;

    return textureMap[currentSprite];
  }

};

#endif
