#ifndef CLIENT_SOUNDCONTROLLER_H_
#define CLIENT_SOUNDCONTROLLER_H_

#include <SDL2pp/SDL2pp.hh>
#include <map>

class SoundController {
	private:
		SDL2pp::Mixer *mixer = NULL;
		std::map<std::string, SDL2pp::Chunk*> sounds;

	public:
		SoundController() {
			mixer = new SDL2pp::Mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
		}

		~SoundController() {
			delete mixer;
		
			for (std::map<std::string, SDL2pp::Chunk*>::iterator it = sounds.begin() ; it != sounds.end() ; ++it ) 
				if (it->second) delete it->second;

			sounds.clear();
		}

		void add(std::string key, SDL2pp::Chunk *chunk) {
			sounds[key] = chunk;
		}

		void remove(std::string key) {
			delete sounds[key];
			sounds[key] = NULL;
		}

		void play(std::string tag) {
			mixer->PlayChannel(-1, *sounds[tag]);
		}

};

#endif
