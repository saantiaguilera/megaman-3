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

			int jump, down, left, right, shoot;
			ss >> jump;
			ss >> down;
			ss >> left;
			ss >> right;
			ss >> shoot;

			KeyMap keyMapReturn(down == 0 ? false : true,
					left == 0 ? false : true,
							right == 0 ? false : true, shoot == 0 ? false : true, jump == 0 ? false : true);

			return keyMapReturn;
		}
};

#endif
