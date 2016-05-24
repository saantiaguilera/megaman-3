#ifndef CLIENT_KEYMAP_H_
#define CLIENT_KEYMAP_H_

#include <string>
#include <sstream>  

class KeyMap {
private:
  bool up, down, left, right, shoot, jump;

public:
  KeyMap(bool up = false,
          bool down = false,
          bool left = false,
          bool right = false,
          bool shoot = false,
          bool jump = false) : up(up), down(down), left(left), right(right),
                        shoot(shoot), jump(jump) {
  }

  ~KeyMap() {

  }

  std::string toString() {
    std::ostringstream os;

    os << "Up::" << (up ? "true" : "false") << "\n";
    os << "Down::" << (down ? "true" : "false") << "\n";
    os << "Left::" << (left ? "true" : "false") << "\n";
    os << "Right::" << (right ? "true" : "false") << "\n";
    os << "Shoot::" << (shoot ? "true" : "false") << "\n";
    os << "Jump::" << (jump ? "true" : "false") << "\n";

    return os.str();
  }

  void setUp(bool u) {
    up = u;
  }

  void setDown(bool d) {
    down = d;
  }

  void setRight(bool r) {
    right = r;
  }

  void setLeft(bool l) {
    left = l;
  }

  void setShooting(bool sh) {
    shoot = sh;
  }

  void setJumping(bool j) {
    jump = j;
  }

  bool isUp() {
    return up;
  }

  //Holy. So salty ::salt::
  bool isDown() {
    return down;
  }

  bool isLeft() {
    return left;
  }

  bool isRight() {
    return right;
  }

  bool isShooting() {
    return shoot;
  }

  bool isJumping() {
    return jump;
  }

};

#endif
