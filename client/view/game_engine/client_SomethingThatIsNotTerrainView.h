#ifndef CLIENT_SOMETHINGTHATISNOTTERRAIN_H_
#define CLIENT_SOMETHINGTHATISNOTTERRAIN_H_
//TODO refactor the name when  you have something better to describe it

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>

#define N_POSITIONS 9

#define STINTV_WIDTH 40
#define STINTV_HEIGHT 42

#define STINTV_SCREEN_WIDTH 76
#define STINTV_SCREEN_HEIGHT 80

class SomethingThatIsNotTerrainView : public RenderedView {
private:
  SDL2pp::Texture *texture;

  int currentSprite = 0;
  int repetitions = 0;

public:
  SomethingThatIsNotTerrainView(SDL2pp::Renderer *renderer) : RenderedView(renderer) {
    texture = new SDL2pp::Texture(*getRenderer(), "res/drawable/some_character.png");
  }

  virtual ~SomethingThatIsNotTerrainView() {
    delete texture;
  }

  virtual void draw() {
    ++repetitions;
    if (repetitions > 3) {
      repetitions = 0;
      ++currentSprite;

      if (currentSprite > N_POSITIONS)
        currentSprite = 0;
    }

    renderer->Copy(*texture, SDL2pp::Rect(100 + STINTV_WIDTH * currentSprite, 0, STINTV_WIDTH, STINTV_HEIGHT),
                                SDL2pp::Rect(300, (8 * 64) - STINTV_SCREEN_HEIGHT, STINTV_SCREEN_WIDTH, STINTV_SCREEN_HEIGHT));
  }

};

#endif
