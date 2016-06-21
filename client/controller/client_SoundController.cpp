#include <iostream>

#include "client_SoundController.h"

SDL2pp::Mixer * SoundController::mixer = NULL;

SoundController::SoundController() {
  if (!mixer)
    mixer = new SDL2pp::Mixer(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

SoundController::~SoundController() {
  if (mixer){
    delete mixer;
  }
}

void SoundController::play(SDL2pp::Chunk sound) {
  if (mixer) {
    mixer->PlayChannel(-1, sound);
    std::cout << "Sound played" << std::endl;
  }
}
