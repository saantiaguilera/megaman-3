#include "client_RenderedView.h"
#include "../../../common/common_MapConstants.h"

#include "client_MegamanView.h"

#define N_POSITIONS 1
#define N_REPETITIONS 1

int MegamanView::megamansCount = 0;

MegamanView::MegamanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
  deviatesMassCenter = true;

  texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_megaman.png");
  megamanNumber = megamansCount;
  megamansCount++;
}

MegamanView::~MegamanView() {
 delete texture;
}

void MegamanView::draw(Point &massCenter) {
  ++repetitions;
  if (repetitions > N_REPETITIONS) {
    repetitions = 0;
    ++currentSprite;

    if (currentSprite > N_POSITIONS)
      currentSprite = 0;
  }

  Point cameraPoint;
  cameraPoint.setX(massCenter.getX() - (renderer->GetOutputWidth() / 2));
  cameraPoint.setY(massCenter.getY() - (renderer->GetOutputHeight() / 2));

  if (getX() >= (cameraPoint.getX() + TERRAIN_TILE_SIZE / 2) && ((unsigned int) (getX() + TERRAIN_TILE_SIZE / 2)) <= (cameraPoint.getX() + renderer->GetOutputWidth()) &&
    getY() >= (cameraPoint.getY() + TERRAIN_TILE_SIZE / 2) && ((unsigned int) (getY() + TERRAIN_TILE_SIZE / 2)) <= (cameraPoint.getY() + renderer->GetOutputHeight())) {
      renderer->Copy(*texture,
        SDL2pp::Rect(0 + TERRAIN_TILE_SIZE * currentSprite, 0,
          TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE),
        SDL2pp::Rect(
          getX() - cameraPoint.getX() - TERRAIN_TILE_SIZE / 2 ,
          getY() - cameraPoint.getY() - TERRAIN_TILE_SIZE / 2,
          TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE));
  }
}

void MegamanView::resetCharacterCount() {
  megamansCount = 0;
}