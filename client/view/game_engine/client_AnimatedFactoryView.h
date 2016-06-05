#ifndef CLIENT_ANIMATEDFACTORYVIEW_H_
#define CLIENT_ANIMATEDFACTORYVIEW_H_

#include "../../../common/common_MapConstants.h"
#include "client_RenderedView.h"
#include "client_AnimatedView.h"

#include "client_MegamanView.h"

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
    			break;
    		case ObstacleViewTypeJumpingSnyper:
    			break;
    		case ObstacleViewTypeMet:
    			break;
    		case ObstacleViewTypeNormalSnyper:
    			break;
    	}

      return view;
    }

};

#endif
