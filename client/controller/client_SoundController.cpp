#include <iostream>

#include "client_SoundController.h"

SDL2pp::Mixer * SoundController::mixer = NULL;

SoundController::SoundController() {
//  if (!mixer)
//    mixer = new SDL2pp::Mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096);
}

SoundController::~SoundController() {
/*  if (mixer){
    delete mixer;
  }*/
}

void SoundController::play(std::string path) {
/*  if (mixer) {
    SDL2pp::Chunk sound = SDL2pp::Chunk(path.c_str());
    sound.SetVolume(MIX_MAX_VOLUME);
    mixer->PlayChannel(-1, sound);
    std::cout << "Sound played" << std::endl;
  }*/
}
