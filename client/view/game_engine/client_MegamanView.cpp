#include <sstream>
#include "client_RenderedView.h"
#include "../../../common/common_MapConstants.h"

#include "client_MegamanView.h"

#define MEGAMAN_SPRITE_COUNT 8

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

  megamanNumber = megamansCount;
  megamansCount++;

  for (int i = 0 ; i < MEGAMAN_SPRITE_COUNT ; ++i) {
    std::stringstream ss;

    switch (megamanNumber) {
      case 0:
        ss << "res/drawable/sprites/sprite_megaman/sprite_megaman" << (i + 1) << "_blue.png";
        break;
      case 1:
        ss << "res/drawable/sprites/sprite_megaman/sprite_megaman" << (i + 1) << "_red.png";
        break;
      case 2:
        ss << "res/drawable/sprites/sprite_megaman/sprite_megaman" << (i + 1) << "_green.png";
        break;
      default:
        ss << "res/drawable/sprites/sprite_megaman/sprite_megaman" << (i + 1) << "_yellow.png";
    }

    textureMap[i] = new SDL2pp::Texture(*getRenderer(), ss.str());
  }
}

MegamanView::~MegamanView() {
  for (int i = 0 ; i < MEGAMAN_SPRITE_COUNT ; ++i)
    delete textureMap[i];
}

SDL2pp::Texture * MegamanView::getTexture(ORIENTATION orient) {
    if (orient == lastOrientation) {
      switch (orient) {
        case UP:
        case DOWN:
        case IDLE:
          break;
        case LEFT:
          spriteStep();
          if (currentSprite > LAST_LEFT)
            currentSprite = FIRST_LEFT;
          break;
        case RIGHT:
          spriteStep();
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

    return textureMap[currentSprite];
}

void MegamanView::resetCharacterCount() {
  megamansCount = 0;
}
