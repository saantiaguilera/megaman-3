#include "client_RenderedView.h"
#include "../../../common/common_MapConstants.h"

#include "client_MegamanView.h"

#define N_POSITIONS 3
#define N_REPETITIONS 3

int MegamanView::megamansCount = 0;

MegamanView::MegamanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
  deviatesMassCenter = true;

  switch (megamansCount) {
    case 0:
      texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_megaman_1.png");
      break;
    case 1:
      texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_megaman_2.png");
      break;
    case 2:
      texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_megaman_3.png");
      break;
    case 3:
      texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_megaman_4.png");
      break;

    default:
      texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/sprites/sprite_megaman_1.png");
  }

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
