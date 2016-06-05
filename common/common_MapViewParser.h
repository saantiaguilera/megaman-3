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


class MapViewParser {
private:
	void parse(rapidjson::Document &document, MapView *mapView);
	void readMapFromFile(const std::string& name, rapidjson::Document* document);

public:
	MapViewParser();
	virtual ~MapViewParser();

	void serverMapFromPath(const std::string& name);
	void editorMapWithPath(MapView *editorMap, std::string name);
	void clientMapFromString(MapView *map, std::string json);
};

#endif /* EDITOR_MODELS_EDITOR_EDITORMAPPARSER_H_ */
