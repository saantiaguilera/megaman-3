#ifndef CLIENT_ANIMATEDVIEW_H_
#define CLIENT_ANIMATEDVIEW_H_

#include "../../../common/common_MapConstants.h"
#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include <SDL2pp/SDL2pp.hh>

#define LEFT 0
#define RIGHT 1
#define IDLE 2

class AnimatedView : public RenderedView {
  protected:
    unsigned int x,y;
    unsigned int id;
    int counter;

    //Because it throws memory corruption if I use a fucking enum
    int mOrientation;

    bool deviatesMassCenter = false;

  public:
    AnimatedView(unsigned int id, SDL2pp::Renderer *renderer) : RenderedView(renderer), id(id), counter(0), mOrientation(IDLE) {
    }

    virtual ~AnimatedView() {
    }

    unsigned int getId() {
      return id;
    }

    //TODO Do polymorphism, the methods below are really similar between classes.
    virtual void draw(Point &massCenter) = 0;

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
      if (this->x - x == 0) {
        counter++;
        if (counter > 5)
          mOrientation = IDLE;
      } else if (this->x - x > 0) {
        mOrientation = LEFT;
        counter = 0;
      } else {
        mOrientation = RIGHT;
        counter = 0;
      }

      this->x = x;
    }
    void setY(unsigned int y) { this->y = y; }

};

#endif
