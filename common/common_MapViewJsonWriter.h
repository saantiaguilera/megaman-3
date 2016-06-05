/*
 * MapViewJsonWriter.h
 *
 *  Created on: Jun 5, 2016
 *      Author: santi
 */

#ifndef COMMON_COMMON_MAPVIEWJSONWRITER_H_
#define COMMON_COMMON_MAPVIEWJSONWRITER_H_

#include "common_MapView.h"

class MapViewJsonWriter {
public:
	MapViewJsonWriter();
	virtual ~MapViewJsonWriter();

	void writeMapInFilenname(MapView *mapView, std::string filename);
};

#endif /* COMMON_COMMON_MAPVIEWJSONWRITER_H_ */
