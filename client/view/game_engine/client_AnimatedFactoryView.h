#ifndef CLIENT_ANIMATEDFACTORYVIEW_H_
#define CLIENT_ANIMATEDFACTORYVIEW_H_

#include "../../../common/common_MapConstants.h"
#include "client_RenderedView.h"
#include "client_AnimatedView.h"

#include "client_MegamanView.h"
#include "client_BumpyView.h"
#include "client_FiremanView.h"
#include "client_JumpingSniperView.h"
#include "client_MagnetmanView.h"
#include "client_MetView.h"
#include "client_RingmanView.h"
#include "client_SniperView.h"
#include "client_SparkmanView.h"
#include "client_BigAmmoView.h"
#include "client_BigEnergyView.h"
#include "client_LifeView.h"
#include "client_SmallAmmoView.h"
#include "client_SmallEnergyView.h"
#include "client_ProjectileView.h"

#include <SDL2pp/SDL2pp.hh>

class AnimatedFactoryView {
  private:
    SDL2pp::Renderer *renderer;

  public:
    AnimatedFactoryView(SDL2pp::Renderer *renderer) : renderer(renderer) {
    }

    virtual ~AnimatedFactoryView() {
    }

    AnimatedView * make(int type, unsigned int id) {
      AnimatedView *view = NULL;

      switch (type) {
        case ObstacleViewTypeMegaman:
          view = new MegamanView(id, renderer);
          break;
    		case ObstacleViewTypeBigAmmoPack:
          view = new BigAmmoView(id, renderer);
    			break;
    		case ObstacleViewTypeBigEnergyCapsule:
          view = new BigEnergyView(id, renderer);
    			break;
    		case ObstacleViewTypeLife:
          view = new LifeView(id, renderer);
    			break;
    		case ObstacleViewTypeSmallAmmoPack:
          view = new SmallAmmoView(id, renderer);
    			break;
    		case ObstacleViewTypeSmallEnergyCapsule:
          view = new SmallEnergyView(id, renderer);
    			break;
    		case ObstacleViewTypeBumpy:
          view = new BumpyView(id, renderer);
    			break;
    		case ObstacleViewTypeJumpingSnyper:
          view = new JumpingSniperView(id, renderer);
    			break;
    		case ObstacleViewTypeMet:
          view = new MetView(id, renderer);
    			break;
    		case ObstacleViewTypeNormalSnyper:
          view = new SniperView(id, renderer);
    			break;
        case ObstacleViewTypeFireman:
          view = new FiremanView(id, renderer);
          break;
        case ObstacleViewTypeMagnetman:
          view = new MagnetmanView(id, renderer);
          break;
        case ObstacleViewTypeRingman:
          view = new RingmanView(id, renderer);
          break;
        case ObstacleViewTypeSparkman:
          view = new SparkmanView(id, renderer);
          break;
        case ObstacleViewTypeBomb:
        case ObstacleViewTypeFire:
        case ObstacleViewTypeMagnet:
        case ObstacleViewTypeRing:
        case ObstacleViewTypeSpark:
        case ObstacleViewTypePlasma:
          view = new ProjectileView(id, renderer);
          break;
    	}

      return view;
    }

};

#endif
