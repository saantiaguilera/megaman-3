#ifndef CLIENT_SPARKMANVIEW_H_
#define CLIENT_SPARKMANVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define SPARKMAN_SPRITE_COUNT 6

class SparkmanView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  SparkmanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < SPARKMAN_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_sparkman/sprite_sparkman" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~SparkmanView() {
    SoundController::play(SDL2pp::Chunk("res/sound/deaths/boss.ogg"));
    for (int i = 0 ; i < SPARKMAN_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    spriteStep();

    if (currentSprite > (SPARKMAN_SPRITE_COUNT - 1))
      currentSprite = 0;

    return textureMap[currentSprite];
  }

};

#endif
