#ifndef CLIENT_LIFEBARVIEW_H_
#define CLIENT_LIFEBARVIEW_H_

#include <iostream>

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>

#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"

#define MAX_BARS 20
#define TEXTURE_TOP 12
#define TEXTURE_BOTTOM 152
#define WIDTH_SPACE 13

class LifeBarView : public RenderedView {
private:
  SDL2pp::Texture *texture;
  int x,y, lifes;

public:
  LifeBarView(SDL2pp::Renderer *renderer) : RenderedView(renderer), texture(NULL), x(0), y(0), lifes(3) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/engine/life_tank.png");
  }

  void setX(int x) {
    this->x = x;
  }

  void setY(int y) {
    this->y = y;
  }

  void setLifes(int lifes) {
    if (lifes > 3)
      lifes = 3;
    if (lifes < 0)
      lifes = 0;
    this->lifes = lifes;
  }

  virtual void draw(Point &massCenter) {
    int height = y;
    int vSpacing = 10;
    for (int i = 0 ; i < lifes ; ++i) {
      getRenderer()->Copy(*texture, SDL2pp::NullOpt,
        SDL2pp::Point(x, height));
      height += texture->GetHeight();
      height += vSpacing;
    }
  }

  virtual ~LifeBarView() {
    if (texture)
      delete texture;
  }

};

#endif
