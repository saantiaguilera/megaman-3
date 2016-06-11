#ifndef CLIENT_ANIMATEDVIEW_H_
#define CLIENT_ANIMATEDVIEW_H_

#include "../../../common/common_MapConstants.h"
#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include <SDL2pp/SDL2pp.hh>

#define MAX_STEP_FOR_IDLE 8

enum ORIENTATION {
  IDLE,
  LEFT,
  RIGHT,
  UP,
  DOWN
};

class AnimatedView : public RenderedView {
  protected:
    unsigned int x,y, previousX, previousY;
    unsigned int id;
    int counter;

    ORIENTATION mOrientation;

    bool deviatesMassCenter = false;

  public:
    AnimatedView(unsigned int id, SDL2pp::Renderer *renderer) : RenderedView(renderer), x(0), y(0), previousX(0), previousY(0), id(id), counter(0), mOrientation(IDLE) {
    }

    virtual ~AnimatedView() {
    }

    unsigned int getId() {
      return id;
    }

    virtual void draw(Point &massCenter) {
      if (x == previousX && y == previousY) {
        counter++;
        if (counter > MAX_STEP_FOR_IDLE)
          mOrientation = IDLE;
      } else {
        counter = 0;
        if (x != previousX) {
          mOrientation = ((int) (x - previousX)) > 0 ? RIGHT : LEFT;
          previousX = x;
        } else {
          mOrientation = ((int) (y - previousY)) > 0 ? UP : DOWN;
          previousY = y;
        }
      }
    }

    virtual void move(unsigned int x, unsigned int y) {
      setX(x);
      setY(y);
    }

    bool doesDeviateMassCenter() {
      return deviatesMassCenter;
    }

    unsigned int getX() { return x; }
    unsigned int getY() { return y; }

    void setX(unsigned int x) {
      this->x = x;
    }

    void setY(unsigned int y) {
      this->y = y;
    }

};

#endif
