#ifndef CLIENT_WORLDVIEW_H_
#define CLIENT_WORLDVIEW_H_

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>

#define TERRAIN_TILE_SIZE 64

class WorldView : public RenderedView {
private:
  SDL2pp::Texture *terrainTexture;

  SDL2pp::Rect *grassRect;
  SDL2pp::Rect *rockRect;
  SDL2pp::Rect *sandRect;
  SDL2pp::Rect *skyRect;
  SDL2pp::Rect *clayRect;

  int xTiles;
  int yTiles;

  void initTextures() {
    terrainTexture = new SDL2pp::Texture(*getRenderer(), "res/drawable/some_tiles.png");

    grassRect = new SDL2pp::Rect(0, 0, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE);
    clayRect  = new SDL2pp::Rect(TERRAIN_TILE_SIZE, 0, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE);
    sandRect  = new SDL2pp::Rect(TERRAIN_TILE_SIZE * 2, 0, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE);
    rockRect  = new SDL2pp::Rect(TERRAIN_TILE_SIZE * 3, 0, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE);
    skyRect   = new SDL2pp::Rect(0, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE);
  }

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
    initTextures();

    //Get the x and y of the matrix
    xTiles = renderer->GetOutputWidth() / TERRAIN_TILE_SIZE;
    yTiles = renderer->GetOutputHeight() / TERRAIN_TILE_SIZE;
  }

  /*
  Currently its for testing purposes. But it should be something similar
  */
  virtual void draw() {
    //Here we should iterate over the whole matrix (In this case I will simply fill the screen)
    for (int i = 0; i < xTiles * yTiles; ++i) { //i < x * y
      int x = i % xTiles; // X position will be position % columns
      int y = i / xTiles; // Y position will be position / columns

      SDL2pp::Rect *rect;

      //Something for testing different textures inside a one
      if (y < 8)
        rect = skyRect;
      else if (y < 9)
        rect = (x % 2 == 0) ? sandRect : grassRect;
      else if (y < 13)
        rect = clayRect;
      else rect = rockRect;

      //For each of them render a texture (imagine background variable you get it from the )
      renderer->Copy(*terrainTexture, *rect, SDL2pp::Rect(x * TERRAIN_TILE_SIZE, y * TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE));
    }
  }

  virtual ~WorldView() {
    delete terrainTexture;
    delete skyRect;
    delete rockRect;
    delete clayRect;
    delete sandRect;
    delete grassRect;
  }

};

#endif
