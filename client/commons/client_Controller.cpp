#include "client_Controller.h"

Context * Controller::getContext() {
   return context;
}

Controller::Controller(Context *ctx) : context(ctx) {

}

Controller::~Controller() {

}
