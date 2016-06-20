#ifndef CLIENT_WORLDVIEW_H_
#define CLIENT_WORLDVIEW_H_

#include <iostream>

#include "client_RenderedView.h"
#include <SDL2pp/SDL2pp.hh>
#include <map>

#include "../../../common/common_MapView.h"
#include "../../../common/common_ObstacleView.h"
#include "../../../common/common_Point.h"
#include "../../../common/common_MapConstants.h"

#define PATH_LADDER "res/drawable/blocks/ladder.png"
#define PATH_BLOCK "res/drawable/blocks/block.png"
#define PATH_NEEDLE "res/drawable/blocks/spike.png"
#define PATH_SKY "res/drawable/blocks/sky.png"
#define PATH_CHAMBER "res/drawable/blocks/boss_lair.png"
#define PATH_BLOCK1 "res/drawable/blocks/block1.png"
#define PATH_BLOCK2 "res/drawable/blocks/block2.png"
#define PATH_BLOCK3 "res/drawable/blocks/block3.png"

class WorldView : public RenderedView {
private:
  SDL2pp::Texture *backgroundTexture;
  SDL2pp::Texture *mapTexture;

  bool textureExists;

public:
  WorldView(SDL2pp::Renderer *renderer) : RenderedView(renderer), backgroundTexture(NULL), mapTexture(NULL), textureExists(false) {
  }

  virtual void draw(Point &massCenter) {
    if (textureExists) {
      Point cameraPoint;
      int rendererWidth, rendererHeight, massCenterX, massCenterY, textureWidth, textureHeight;
      rendererWidth = getRenderer()->GetOutputWidth();
      rendererHeight = getRenderer()->GetOutputHeight();
      massCenterX = massCenter.getX();
      massCenterY = massCenter.getY();

      textureWidth = mapTexture->GetWidth();
      textureHeight = mapTexture->GetHeight();

      bool hasXLeftPadding = (massCenterX - (rendererWidth / 2)) < 0;
      bool hasXRightPadding = (massCenterX + (rendererWidth / 2)) > textureWidth;
      bool hasNoXPadding = !hasXRightPadding && !hasXLeftPadding;


      if (hasXLeftPadding) {
        cameraPoint.setX(0);
        massCenter.setX(rendererWidth / 2);
      }

      if (hasXRightPadding) {
        cameraPoint.setX(textureWidth - rendererWidth);
        massCenter.setX(textureWidth - (rendererWidth / 2));
      }

      if (hasNoXPadding) {
          cameraPoint.setX(massCenterX - rendererWidth / 2);
      }


      bool hasYTopPadding = (massCenterY - (rendererHeight / 2)) < 0;
      bool hasYBotomPadding = (massCenterY + (rendererHeight / 2)) > textureHeight;
      bool hasNoYPadding = !hasYTopPadding && !hasYBotomPadding;


      if (hasYTopPadding) {
        cameraPoint.setY(0);
        massCenter.setY(rendererHeight / 2);
      }

      if (hasYBotomPadding) {
        cameraPoint.setY(textureHeight - rendererHeight);
        massCenter.setY(textureHeight - (rendererHeight / 2));
      }

      if (hasNoYPadding) {
          cameraPoint.setY(massCenterY - rendererHeight / 2);
      }

      int backgroundX = (backgroundTexture->GetWidth() - rendererWidth) == 0 ? 0 : cameraPoint.getX() % (backgroundTexture->GetWidth() - rendererWidth);
      int backgroundY = (backgroundTexture->GetHeight() - rendererHeight) == 0 ? 0 : cameraPoint.getY() % (backgroundTexture->GetHeight() - rendererHeight);

      renderer->Copy(*backgroundTexture, SDL2pp::Rect(
            backgroundX, backgroundY,
            rendererWidth, rendererHeight));
      renderer->Copy(*mapTexture, SDL2pp::Rect(
            cameraPoint.getX(),
            cameraPoint.getY(),
            rendererWidth, rendererHeight));
    }
  }

  void from(MapView *mapView) {
    textureExists = false;

    std::map<ObstacleViewType, SDL2pp::Surface*> texturesMap;
    texturesMap[ObstacleViewTypeLadder] = new SDL2pp::Surface(PATH_LADDER);
    texturesMap[ObstacleViewTypeBlock] = new SDL2pp::Surface(PATH_BLOCK);
    texturesMap[ObstacleViewTypeNeedle] = new SDL2pp::Surface(PATH_NEEDLE);
    texturesMap[ObstacleViewTypePrecipice] = new SDL2pp::Surface(PATH_SKY);
    texturesMap[ObstacleViewTypeBossChamberGate] = new SDL2pp::Surface(PATH_CHAMBER);
    texturesMap[ObstacleViewTypeBlock1] = new SDL2pp::Surface(PATH_BLOCK1);
    texturesMap[ObstacleViewTypeBlock2] = new SDL2pp::Surface(PATH_BLOCK2);
    texturesMap[ObstacleViewTypeBlock3] = new SDL2pp::Surface(PATH_BLOCK3);

    if (mapTexture)
      delete mapTexture;

    if (backgroundTexture)
      delete backgroundTexture;

    int mWidth = mapView->getWidth() + TERRAIN_TILE_SIZE < (unsigned int) getRenderer()->GetOutputWidth() ? getRenderer()->GetOutputWidth() : mapView->getWidth() + TERRAIN_TILE_SIZE ;
    int mHeight = mapView->getHeight() + TERRAIN_TILE_SIZE < (unsigned int) getRenderer()->GetOutputHeight() ? getRenderer()->GetOutputHeight() : mapView->getHeight() + TERRAIN_TILE_SIZE ;

    mapTexture = new SDL2pp::Texture(*getRenderer(), SDL_PIXELFORMAT_RGBA8888,
          SDL_TEXTUREACCESS_TARGET, mWidth, mHeight);

    mapTexture->SetBlendMode(SDL_BLENDMODE_BLEND);

    backgroundTexture = new SDL2pp::Texture(*getRenderer(), mapView->getBackgroundImage());

    //Iterate the map with the stuff we should draw and if its of that type, draw it where it is
    std::vector<ObstacleView*> * views = mapView->getObstacles();
    for (unsigned int i = 0 ; i < views->size() ; ++i) {
      ObstacleView *view = views->at(i);

      std::map<ObstacleViewType, SDL2pp::Surface*>::iterator it = texturesMap.find(view->getType());
      if (it != texturesMap.end()) {
        mapTexture->Update(SDL2pp::Rect(
            view->getPoint().getX() - TERRAIN_TILE_SIZE / 2,
            view->getPoint().getY() - TERRAIN_TILE_SIZE / 2,
            TERRAIN_TILE_SIZE, TERRAIN_TILE_SIZE),
            *it->second);
      }
    }

    delete texturesMap[ObstacleViewTypeBlock1];
    delete texturesMap[ObstacleViewTypeLadder];
    delete texturesMap[ObstacleViewTypeBlock];
    delete texturesMap[ObstacleViewTypeNeedle];
    delete texturesMap[ObstacleViewTypePrecipice];
    delete texturesMap[ObstacleViewTypeBossChamberGate];
    delete texturesMap[ObstacleViewTypeBlock2];
    delete texturesMap[ObstacleViewTypeBlock3];

    textureExists = true;
  }

  virtual ~WorldView() {
    textureExists = false;

    if (mapTexture)
      delete mapTexture;

    if (backgroundTexture)
      delete backgroundTexture;
  }

};

#endif
