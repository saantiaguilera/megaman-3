/*
 * EditorMapParser.h
 *
 *  Created on: May 29, 2016
 *      Author: santi
 */

#ifndef EDITOR_MODELS_EDITOR_EDITORMAPPARSER_H_
#define EDITOR_MODELS_EDITOR_EDITORMAPPARSER_H_

#include "common_MapView.h"
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"


class MapVeiwParser {
public:
	MapVeiwParser();
	virtual ~MapVeiwParser();

	void editorMapWithPath(MapView *editorMap, std::string name);
};

#endif /* EDITOR_MODELS_EDITOR_EDITORMAPPARSER_H_ */
