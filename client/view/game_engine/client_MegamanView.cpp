#include "client_RenderedView.h"
#include "../../../common/common_MapConstants.h"

#include "client_MegamanView.h"

#define N_POSITIONS 3
#define N_REPETITIONS 3

#define FIRST_LEFT 4
#define LAST_LEFT 6

#define IDLE_LEFT 7
#define IDLE_RIGHT 0

#define FIRST_RIGHT 1
#define LAST_RIGHT 3

int MegamanView::megamansCount = 0;

MegamanView::MegamanView(unsigned int id, SDL2pp::Renderer *renderer) : AnimatedView(id, renderer) {
  deviatesMassCenter = true;
  lastOrientation = IDLE;

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

void MegamanView::step() {
  ++repetitions;
  if (repetitions > N_REPETITIONS) {
    repetitions = 0;
    ++currentSprite;
  }
}

SDL2pp::Texture * MegamanView::getTexture(ORIENTATION orient) {
    if (orient == lastOrientation) {
      switch (orient) {
        case UP:
        case DOWN:
        case IDLE:
          break;
        case LEFT:
          step();
          if (currentSprite > LAST_LEFT)
            currentSprite = FIRST_LEFT;
          break;
        case RIGHT:
          step();
          if (currentSprite > LAST_RIGHT)
            currentSprite = FIRST_RIGHT;
          break;
      }
    } else {
      switch (orient) {
        case UP:
        case DOWN:
        case IDLE:
          if (lastOrientation == LEFT)
            currentSprite = IDLE_LEFT;
          else currentSprite = IDLE_RIGHT;
          break;
        case LEFT:
          currentSprite = FIRST_LEFT;
          break;
        case RIGHT:
          currentSprite = FIRST_RIGHT;
          break;
      }
    }

    lastOrientation = orient;

    return texture;
}

SDL2pp::Rect * MegamanView::getSRCRect() {
  return new SDL2pp::Rect(0 + TERRAIN_REAL_TILE_SIZE * currentSprite, 0,
    TERRAIN_REAL_TILE_SIZE, TERRAIN_REAL_TILE_SIZE);
}

void MegamanView::resetCharacterCount() {
  megamansCount = 0;
}
