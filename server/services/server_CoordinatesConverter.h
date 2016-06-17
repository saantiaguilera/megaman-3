/*
 * server_CoordinatesConverter.h
 *
 *  Created on: Jun 15, 2016
 *      Author: mastanca
 */

#ifndef SERVER_SERVICES_SERVER_COORDINATESCONVERTER_H_
#define SERVER_SERVICES_SERVER_COORDINATESCONVERTER_H_

#include "../../common/common_MapConstants.h"

class CoordinatesConverter {
public:
	// Constructor
	CoordinatesConverter();
	// Destroyer
	virtual ~CoordinatesConverter();
	// Converts pixels to meters
	float pxToMeters(float x);
	// Convert meters to px
	float metersToPx(float x);
private:
	// Copy constructor
	CoordinatesConverter(const CoordinatesConverter&);
	// Assignment operator
	CoordinatesConverter& operator=(const CoordinatesConverter&);
};

#endif /* SERVER_SERVICES_SERVER_COORDINATESCONVERTER_H_ */
