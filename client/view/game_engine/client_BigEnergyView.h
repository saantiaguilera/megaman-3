#ifndef CLIENT_BIGENERGYVIEW_H_
#define CLIENT_BIGENERGYVIEW_H_

#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"
#include <SDL2pp/SDL2pp.hh>

class BigEnergyView : public AnimatedView {
private:
  SDL2pp::Texture *texture;

public:
  BigEnergyView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/powerups/energy/energy_big.png");
  }

  virtual ~BigEnergyView() {
    delete texture;
  }

  virtual void draw(Point &massCenter) {
    Point cameraPoint;
    cameraPoint.setX(massCenter.getX() - (renderer->GetOutputWidth() / 2));
    cameraPoint.setY(massCenter.getY() - (renderer->GetOutputHeight() / 2));

    if (getX() >= (cameraPoint.getX() + TERRAIN_TILE_SIZE / 2) && ((unsigned int) (getX() + TERRAIN_TILE_SIZE / 2)) <= (cameraPoint.getX() + renderer->GetOutputWidth()) &&
      getY() >= (cameraPoint.getY() + TERRAIN_TILE_SIZE / 2) && ((unsigned int) (getY() + TERRAIN_TILE_SIZE / 2)) <= (cameraPoint.getY() + renderer->GetOutputHeight())) {
        renderer->Copy(*texture,
          SDL2pp::NullOpt,
          SDL2pp::Rect(
            getX() - cameraPoint.getX() - TERRAIN_TILE_SIZE / 2 ,
            getY() - cameraPoint.getY() - TERRAIN_TILE_SIZE / 2,
            TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE));
    }
  }

};

#endif
