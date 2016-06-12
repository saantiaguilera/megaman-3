#ifndef CLIENT_SMALLENERGYVIEW_H_
#define CLIENT_SMALLENERGYVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

class SmallEnergyView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

public:
  SmallEnergyView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/powerups/energy/energy.png");
  }

  virtual ~SmallEnergyView() {
    delete texture;
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    return texture;
  }

};

#endif
