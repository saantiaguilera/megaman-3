#ifndef SERVER_KEYMAPPARSER_H_
#define SERVER_KEYMAPPARSER_H_

#include <sstream>
#include <string>

#include "../services/server_KeyMap.h"

class KeyMapParser {
	public:
		KeyMapParser() {
		}

		~KeyMapParser() {
		}

		KeyMap parse(std::string string) {
			std::stringstream ss;
			ss.str(string);

			bool jump, down, left, right, shoot;
			ss >> jump;
			ss >> down;
			ss >> left;
			ss >> right;
			ss >> shoot;

			return KeyMap(down, left, right, shoot, jump);
		}
};

#endif
