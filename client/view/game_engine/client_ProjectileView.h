#ifndef CLIENT_PROJECTILEVIEW_H_
#define CLIENT_PROJECTILEVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

class ProjectileView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

public:
  ProjectileView(unsigned int id, int type, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    std::string path = "res/drawable/bullets/";

    switch (type) {
      case ObstacleViewTypeBomb:
        path += "bomb";
        break;
      case ObstacleViewTypeFire:
        path += "fire";
        break;
      case ObstacleViewTypeMagnet:
        path += "magnet";
        break;
      case ObstacleViewTypeRing:
        path += "ring";
        break;
      case ObstacleViewTypeSpark:
        path += "spark";
        break;
      case ObstacleViewTypePlasma:
        path += "normal";
        break;
    }

    path += "_bullet.png";

    texture = new SDL2pp::Texture(*getRenderer(), path);
  }

  virtual ~ProjectileView() {
    delete texture;
  }

  virtual SDL2pp::Texture * getTexture(ORIENTATION orient) {
    return texture;
  }

};

#endif
