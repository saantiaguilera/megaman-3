#ifndef CLIENT_ANIMATEDVIEW_H_
#define CLIENT_ANIMATEDVIEW_H_

#include <queue>
#include "../../../common/common_MapConstants.h"
#include "client_RenderedView.h"
#include "../../../common/common_Point.h"
#include <SDL2pp/SDL2pp.hh>

#define N_REPETITIONS 3

#define MAX_STEP_FOR_IDLE 4

enum ORIENTATION {
  IDLE,
  LEFT,
  RIGHT,
  UP,
  DOWN
};

class AnimatedView : public RenderedView {
  private:
    std::queue<Point> movementList;
    unsigned int currentX, currentY;
    unsigned int id;
    int counter;

    ORIENTATION mOrientation;

  protected:
    bool deviatesMassCenter = false;

    int currentSprite = 0;
    int repetitions = 0;

    void spriteStep() {
      ++repetitions;
      if (repetitions > N_REPETITIONS) {
        repetitions = 0;
        ++currentSprite;
      }
    }

  public:
    AnimatedView(unsigned int id, SDL2pp::Renderer *renderer) : RenderedView(renderer), currentX(0), currentY(0), id(id), counter(0), mOrientation(IDLE) {
    }

    virtual ~AnimatedView() {
    }

    unsigned int getId() {
      return id;
    }

    void add(Point &point) {
      movementList.push(point);
    }

    virtual SDL2pp::Texture * getTexture(ORIENTATION orient) = 0;

    virtual void draw(Point &massCenter) {
      unsigned int futureX, futureY;
      if (movementList.size() > 0) {
        Point point = movementList.front();
        movementList.pop();
        futureX = point.getX();
        futureY = point.getY();
      } else {
        futureX = currentX;
        futureY = currentY;
      }

      if (futureX == currentX && futureY == currentY) {
        counter++;
        if (counter > MAX_STEP_FOR_IDLE)
          mOrientation = IDLE;
      } else {
        counter = 0;
        if (futureX != currentX) {
          mOrientation = ((int) (futureX - currentX)) > 0 ? RIGHT : LEFT;
          currentX = futureX;
        } else {
          mOrientation = ((int) (futureY - currentY)) > 0 ? UP : DOWN;
          currentY = futureY;
        }
      }

      Point cameraPoint;
      cameraPoint.setX(massCenter.getX() - (renderer->GetOutputWidth() / 2));
      cameraPoint.setY(massCenter.getY() - (renderer->GetOutputHeight() / 2));

      if (futureX >= (cameraPoint.getX()) && futureX <= (cameraPoint.getX() + renderer->GetOutputWidth()) &&
        futureY >= (cameraPoint.getY()) && futureY <= (cameraPoint.getY() + renderer->GetOutputHeight())) {
        renderer->Copy(*getTexture(mOrientation),
          SDL2pp::NullOpt,
          SDL2pp::Point(
            futureX - cameraPoint.getX() - TERRAIN_TILE_SIZE / 2,
            futureY - cameraPoint.getY() - TERRAIN_TILE_SIZE / 2));
      }

      currentX = futureX;
      currentY = futureY;
    }

    bool doesDeviateMassCenter() {
      return deviatesMassCenter;
    }

    unsigned int getX() { return currentX; }
    unsigned int getY() { return currentY; }

};

#endif
