#ifndef CLIENT_WORLDVIEW_H_
#define CLIENT_WORLDVIEW_H_

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>
#include <map>

#include "../../../common/common_MapView.h"
#include "../../../common/common_ObstacleView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"

#define PATH_LADDER "./res/drawable/blocks/ladder.png"
#define PATH_BLOCK "./res/drawable/blocks/block.png"
#define PATH_NEEDLE "./res/drawable/blocks/spike.png"
#define PATH_SKY "./res/drawable/blocks/sky.jpg"

#define TERRAIN_TILE_SIZE 100

class WorldView : public RenderedView {
private:
  SDL2pp::Texture *texture;

public:
  WorldView(SDL2pp::Renderer *renderer) : RenderedView(renderer) {
  }

  virtual void draw() {
      renderer->Copy(*texture, SDL2pp::Rect(0, 0, renderer->GetOutputWidth(), renderer->GetOutputHeight()));
  }

  void from(MapView *mapView) {
    std::map<ObstacleViewType, SDL2pp::Surface*> texturesMap;
    texturesMap[ObstacleViewTypeLadder] = new SDL2pp::Surface(PATH_LADDER);
    texturesMap[ObstacleViewTypeBlock] = new SDL2pp::Surface(PATH_BLOCK);
    texturesMap[ObstacleViewTypeNeedle] = new SDL2pp::Surface(PATH_NEEDLE);
    texturesMap[ObstacleViewTypePrecipice] = new SDL2pp::Surface(PATH_SKY);

    if (texture)
      delete texture;

    texture = new SDL2pp::Texture(*getRenderer(), SDL_PIXELFORMAT_RGBA8888,
          SDL_TEXTUREACCESS_TARGET, mapView->getWidth(), mapView->getHeight());
    //TODO Use texture lock ?

    //Fill all the texture with sky
    SDL2pp::Surface *skySurface = new SDL2pp::Surface(PATH_SKY);

    for (unsigned int i = 0 ; i < mapView->getWidth() ; i += TERRAIN_TILE_SIZE) {
      for (unsigned int j = 0 ; j < mapView->getHeight() ; j += TERRAIN_TILE_SIZE) {
        texture->Update(SDL2pp::Rect(i, j, TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE),
          *skySurface);
      }
    }

    //Iterate the map with the stuff we should draw and if its of that type, draw it where it is
    std::vector<ObstacleView*> * views = mapView->getObstacles();
    for (unsigned int i = 0 ; i < views->size() ; ++i) {
      ObstacleView *view = views->at(i);

      std::map<ObstacleViewType, SDL2pp::Surface*>::iterator it = texturesMap.find(view->getType());
      if (it != texturesMap.end()) {
        texture->Update(SDL2pp::Rect(view->getPoint().getX(), view->getPoint().getY(), TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE),
            *texturesMap[view->getType()]);
      }
    }

    delete texturesMap[ObstacleViewTypeLadder];
    delete texturesMap[ObstacleViewTypeBlock];
    delete texturesMap[ObstacleViewTypeNeedle];
    delete texturesMap[ObstacleViewTypePrecipice];
    delete skySurface;
  }

  virtual ~WorldView() {
    delete texture;
  }

};

#endif
