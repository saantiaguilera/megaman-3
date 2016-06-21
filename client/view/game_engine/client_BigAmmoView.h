#ifndef CLIENT_BIGAMMOVIEW_H_
#define CLIENT_BIGAMMOVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

class BigAmmoView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

public:
  BigAmmoView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/powerups/ammo/big_ammo.png");
  }

  virtual ~BigAmmoView() {
    SoundController::play(SDL2pp::Chunk("res/sound/powerups/ammoup.wav"));
    delete texture;
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    return texture;
  }

};

#endif
