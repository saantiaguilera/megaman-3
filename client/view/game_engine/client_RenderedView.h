#ifndef CLIENT_RENDEREDVIEW_H_
#define CLIENT_RENDEREDVIEW_H_

#include <SDL2pp/SDL2pp.hh>

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

  virtual void draw() = 0;
};

#endif
