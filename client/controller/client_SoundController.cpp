#include "client_SoundController.h"

SDL2pp::Mixer * SoundController::mixer = new SDL2pp::Mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

SoundController::SoundController() {

}

SoundController::~SoundController() {
  if (mixer){
    delete mixer;
  }
}

void SoundController::play(SDL2pp::Chunk sound) {
  if (mixer)
    mixer->PlayChannel(-1, sound);
}
