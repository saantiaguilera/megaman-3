#ifndef CLIENT_WORLDVIEW_H_
#define CLIENT_WORLDVIEW_H_

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>

#include "../../../common/common_MapView.h"

#define TERRAIN_TILE_SIZE 100

class WorldView : public RenderedView {
private:
  SDL2pp::Texture *texture;

public:
  /**
  * We will parse the whole map inside a matrix (that will have ordered all the tiles)
  *
  *  This means: If theres a tile in (0,0), (0,40) and (0,120)
  * and the tile size is 40, then the matrix will be
  |X| -> Has a tile
  |X| -> Has a tile
  | | -> Has a NULL object
  |X| -> Has a tile
  * We will iterate over the whole matrix and create a single texture with the whole map (yikes)
  * This will be done in the constructor.
  * Note: When theres no tile we should define a default image (or just put a black one ?)
  *
  * Then in a method called onDraw it will have a "mass center" and it will just draw a rect of the texture around the mass center inside the SDL2Pp::Renderer
  * (That renderer is the window the user sees)
  *
  * note that currently I just show the stuff in the renderer because I still havent parse the map and I dont have a mass center to scroll over
  */
  WorldView(SDL2pp::Renderer *renderer) : RenderedView(renderer) {
  }

  virtual void draw() {
      //For each of them render a texture (imagine background variable you get it from the )
      //renderer->Copy(*terrainTexture, *rect, SDL2pp::Rect(x * TERRAIN_TILE_SIZE, y * TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE));
  }

  void from(MapView *mapView) {
    texture = new SDL2pp::Texture(*getRenderer(), SDL_PIXELFORMAT_RGBA8888,
          SDL_TEXTUREACCESS_TARGET, mapView->getWidth(), mapView->getHeight());
  }

  virtual ~WorldView() {
    delete texture;
  }

};

#endif
