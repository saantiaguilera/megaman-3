#ifndef CLIENT_MEGAMANVIEW_H_
#define CLIENT_MEGAMANVIEW_H_

#include "client_AnimatedView.h"
#include "../../../common/common_Point.h"
#include <SDL2pp/SDL2pp.hh>

class MegamanView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

  //ORIENTATION lastOrientation;

  int currentSprite = 0;
  int repetitions = 0;

  //Used for knowing if we have to draw megaman of what color
  static int megamansCount;
  int megamanNumber = 0;

public:
  MegamanView(unsigned int id, SDL2pp::Renderer *renderer);
  virtual ~MegamanView();

  virtual void draw(Point &massCenter);
  static void resetCharacterCount();

};

#endif
