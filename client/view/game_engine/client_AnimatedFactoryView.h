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

#include <SDL2pp/SDL2pp.hh>

class AnimatedFactoryView {
  private:
    SDL2pp::Renderer *renderer;

  public:
    AnimatedFactoryView(SDL2pp::Renderer *renderer) : renderer(renderer) {
    }

    virtual ~AnimatedFactoryView() {
    }

    AnimatedView * make(int type) {
      AnimatedView *view = NULL;

      switch (type) {
        case ObstacleViewTypeMegaman:
          view = new MegamanView(renderer);
          break;
    		case ObstacleViewTypeBigAmmoPack:
          view = new BigAmmoView(renderer);
    			break;
    		case ObstacleViewTypeBigEnergyCapsule:
          view = new BigEnergyView(renderer);
    			break;
    		case ObstacleViewTypeLife:
          view = new LifeView(renderer);
    			break;
    		case ObstacleViewTypeSmallAmmoPack:
          view = new SmallAmmoView(renderer);
    			break;
    		case ObstacleViewTypeSmallEnergyCapsule:
          view = new SmallEnergyView(renderer);
    			break;
    		case ObstacleViewTypeBumpy:
          view = new BumpyView(renderer);
    			break;
    		case ObstacleViewTypeJumpingSnyper:
          view = new JumpingSniperView(renderer);
    			break;
    		case ObstacleViewTypeMet:
          view = new MetView(renderer);
    			break;
    		case ObstacleViewTypeNormalSnyper:
          view = new SniperView(renderer);
    			break;
        case ObstacleViewTypeFire:
          view = new FiremanView(renderer);
          break;
        case ObstacleViewTypeMagnet:
          view = new MagnetmanView(renderer);
          break;
        case ObstacleViewTypeRing:
          view = new RingmanView(renderer);
          break;
        case ObstacleViewTypeSpark:
          view = new SparkmanView(renderer);
    	}

      return view;
    }

};

#endif
