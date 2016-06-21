#ifndef CLIENT_SOUNDCONTROLLER_H_
#define CLIENT_SOUNDCONTROLLER_H_

#include <SDL2pp/SDL2pp.hh>

class SoundController {
	private:
		static SDL2pp::Mixer *mixer;

	public:
		SoundController();
		~SoundController();

		static void play(SDL2pp::Chunk sound);

};

#endif
