#include "client_Handler.h"

class Context;

#include <gtkmm.h>
#include "client_Controller.h"
#include "client_Context.h"

Context * Controller::getContext() {
   return context;
}

Controller::Controller(Context *ctx) : context(ctx) {

}

Controller::~Controller() {

}
