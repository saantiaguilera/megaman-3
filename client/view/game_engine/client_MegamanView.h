#ifndef CLIENT_MEGAMANVIEW_H_
#define CLIENT_MEGAMANVIEW_H_

#include <map>
#include "client_AnimatedView.h"
#include "../../../common/common_Point.h"
#include <SDL2pp/SDL2pp.hh>

class MegamanView : public AnimatedView {
private:
  ORIENTATION lastOrientation;

  std::map<int, SDL2pp::Texture*> textureMap;

  //Used for knowing if we have to draw megaman of what color
  static int megamansCount;
  int megamanNumber = 0;

public:
  MegamanView(unsigned int id, SDL2pp::Renderer *renderer);
  virtual ~MegamanView();

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient);
  static void resetCharacterCount();

};

#endif
