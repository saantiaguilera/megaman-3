#ifndef CLIENT_SNIPERVIEW_H_
#define CLIENT_SNIPERVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

class SniperView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

public:
  SniperView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_sniper/sprite_sniper1.png");
  }

  virtual ~SniperView() {
    SoundController::play(("res/sound/deaths/mob.wav"));
    delete texture;
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    return texture;
  }

};

#endif
