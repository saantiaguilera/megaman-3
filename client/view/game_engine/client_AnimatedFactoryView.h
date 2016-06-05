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
    			break;
    		case ObstacleViewTypeBigEnergyCapsule:
    			break;
    		case ObstacleViewTypeLife:
    			break;
    		case ObstacleViewTypeSmallAmmoPack:
    			break;
    		case ObstacleViewTypeSmallEnergyCapsule:
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
    	}

      return view;
    }

};

#endif
