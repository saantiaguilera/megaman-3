#ifndef CLIENT_RENDEREDVIEW_H_
#define CLIENT_RENDEREDVIEW_H_

#include <SDL2pp/SDL2pp.hh>
#include "../../../common/common_Point.h"

//renderer->Copy(Texture, Rect for cropping the texture, Rect for scaling the texture inside the renderer)

class RenderedView {
protected:
  SDL2pp::Renderer *renderer;

  SDL2pp::Renderer * getRenderer() {
    return renderer;
  }

public:
  RenderedView(SDL2pp::Renderer *renderer) : renderer(renderer) {

  }

  ~RenderedView() {

  }

  virtual void draw(Point &massCenter) = 0;
};

#endif
