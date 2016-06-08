#ifndef CLIENT_DEFAULTBARVIEW_H_
#define CLIENT_DEFAULBARVIEW_H_

#include <iostream>

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>

#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"

#define MAX_BARS 20
#define TEXTURE_TOP 12
#define TEXTURE_BOTTOM 152
#define WIDTH_SPACE 13

class DefaultBarView : public RenderedView {
private:
  SDL2pp::Texture *barTexture;
  SDL2pp::Texture *healthTexture;

protected:
  int x,y, amountPercentage;

public:
  DefaultBarView(SDL2pp::Renderer *renderer) : RenderedView(renderer), barTexture(NULL), x(0), y(0), amountPercentage(100) {
    barTexture = new SDL2pp::Texture(*getRenderer(), "res/drawable/engine/empty_health.png");
    healthTexture = new SDL2pp::Texture(*getRenderer(), "res/drawable/engine/health_bar.png");
  }

  void setX(int x) {
    this->x = x;
  }

  void setY(int y) {
    this->y = y;
  }

  void setAmountPercentage(int percentage) {
    if (percentage > 100)
      percentage = 100;
    if (percentage < 0)
      percentage = 0;
    this->amountPercentage = percentage;
  }

  virtual void draw(Point &massCenter) {
    getRenderer()->Copy(*barTexture, SDL2pp::NullOpt,
      SDL2pp::Point(x,y));

    //100 -> 20 // n -> ?
    int vSpacing = 2;
    int hSpacing = 3;
    int height = y + TEXTURE_BOTTOM - vSpacing;
    for (int i = 0 ; i < amountPercentage * MAX_BARS / 100 ; i++) {
      getRenderer()->Copy(*healthTexture, SDL2pp::NullOpt,
        SDL2pp::Point(x + WIDTH_SPACE + hSpacing,
          height - healthTexture->GetHeight()));

      height -= healthTexture->GetHeight();
      height -= vSpacing;
    }
  }

  virtual ~DefaultBarView() {
    if (barTexture)
      delete barTexture;
    if (healthTexture)
      delete healthTexture;
  }

};

#endif
