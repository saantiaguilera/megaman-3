#ifndef CLIENT_RINGMANVIEW_H_
#define CLIENT_RINGMANVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

#define N_POSITIONS 1

#define N_REPETITIONS 1

class RingmanView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

  int currentSprite = 0;
  int repetitions = 0;

public:
  RingmanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_ringman.png");
  }

  virtual ~RingmanView() {
    delete texture;
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    return texture;
  }

  virtual SDL2pp::Rect * getSRCRect() {
    return new SDL2pp::Rect(0, 0, TERRAIN_REAL_TILE_SIZE, TERRAIN_REAL_TILE_SIZE);
  }

};

#endif
