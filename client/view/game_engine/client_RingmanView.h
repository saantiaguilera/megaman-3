#ifndef CLIENT_RINGMANVIEW_H_
#define CLIENT_RINGMANVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

#define RINGMAN_SPRITE_COUNT 10

class RingmanView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  RingmanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < RINGMAN_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_ringman/sprite_ringman" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~RingmanView() {
    for (int i = 0 ; i < RINGMAN_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    spriteStep();

    if (currentSprite > (RINGMAN_SPRITE_COUNT - 1))
      currentSprite = 0;

    return textureMap[currentSprite];
  }

};

#endif
