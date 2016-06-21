#ifndef CLIENT_JUMPINGSNIPERVIEW_H_
#define CLIENT_JUMPINGSNIPERVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include "../../controller/client_SoundController.h"
#include <SDL2pp/SDL2pp.hh>

#define JUMPING_SNIPER_SPRITE_COUNT 7

class JumpingSniperView : public AnimatedView {
private:
  std::map<int, SDL2pp::Texture*> textureMap;

public:
  JumpingSniperView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    for (int i = 0 ; i < JUMPING_SNIPER_SPRITE_COUNT ; ++i) {
      std::stringstream ss;
      ss << "res/drawable/sprites/sprite_jumping_sniper/sprite_jumping_sniper" << (i + 1) << ".png";
      textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
    }
  }

  virtual ~JumpingSniperView() {
    SoundController::play(("res/sound/deaths/mob.wav"));
    for (int i = 0 ; i < JUMPING_SNIPER_SPRITE_COUNT ; ++i)
      delete textureMap[i];
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    spriteStep();

    if (currentSprite > (JUMPING_SNIPER_SPRITE_COUNT - 1))
      currentSprite = 0;

    return textureMap[currentSprite];
  }

};

#endif
