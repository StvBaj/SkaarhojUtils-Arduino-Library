/*  SkaarhojUtils Arduino library with various utilities for products from SKAARHOJ.com
    Copyright (C) 2012 Kasper Skårhøj    <kasperskaarhoj@gmail.com> 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SkaarhojUtils_H
#define SkaarhojUtils_H

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/**
  Version 1.1.0
	(Semantic Versioning)
**/

class SkaarhojUtils
{
  private:
	int _uniDirectionalSlider_sliderTolerance;
    int _uniDirectionalSlider_sliderLowEndOffset;
    int _uniDirectionalSlider_sliderHighEndOffset;
	int _uniDirectionalSlider_previousSliderValue;
	int _uniDirectionalSlider_previousTransitionPosition;
	bool _uniDirectionalSlider_sliderDirectionUp;
	
	bool _encoders_countOn[2];
	int _encoders_triggerCache[2];
	bool _encoders_pushOn[2];
	bool _encoders_pushOnTriggerTimeFired[2];
	unsigned long _encoders_pushOnMillis[2];
	uint8_t _encoders_interruptState[2];
	int _encoders_interruptStateNum[2];	// TEMP
	
	int _touch_Xthreshold;
	int _touch_Ythreshold;
	int _touch_rawXVal;
	int _touch_rawYVal;
	bool _touch_isTouchedState;
	bool _touch_exitByTapAndHold;
	bool _touch_checkingForTapAndHold;
	unsigned long _touch_touchStartedTime;
	unsigned long _touch_touchStartedTime2;
	unsigned long _touch_touchStartedTime3;
	int _touch_touchStartedRawXVal;
	int _touch_touchStartedRawYVal;
	int _touch_touchEndedRawXVal;
	int _touch_touchEndedRawYVal;
	int _touch_touchRawXValRoundRobin[8];
	int _touch_touchRawYValRoundRobin[8];
	int _touch_touchRawXValMax;
	int _touch_touchRawXValMin;
	int _touch_touchRawYValMax;
	int _touch_touchRawYValMin;
	uint8_t _touch_touchCoordRoundRobinIdx;
	unsigned int _touch_touchTimeThreshold;
	unsigned int _touch_touchTimeTapAndHold;
	uint8_t _touch_touchPerimiterThreshold;
	uint8_t _touch_gestureRatio;
	uint16_t _touch_gestureLength;
	int _touch_marginLeft;
	int _touch_marginRight;
	int _touch_marginTop;
	int _touch_marginBottom;
	uint8_t _touch_snapToBorderZone;
	unsigned int _touch_scaleRangeX;
	unsigned int _touch_scaleRangeY;
	
  public:
	SkaarhojUtils();
	
		// Slider functions:
	void uniDirectionalSlider_init();
	bool uniDirectionalSlider_hasMoved();
	int uniDirectionalSlider_position();
	bool uniDirectionalSlider_isAtEnd();
	
		// Encoder functions:
	void encoders_init();
	int encoders_state(uint8_t encNum);
	int encoders_state(uint8_t encNum, unsigned int buttonPushTriggerDelay);
	void encoders_interrupt(uint8_t encNum);
	
		// Touch functions:
	void touch_init();
	void touch_calibrationPointRawCoordinates(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y, int p4x, int p4y);
	bool touch_isTouched();
	int touch_getRawXVal();
	int touch_getRawYVal();
	bool touch_isInProgress();
	uint8_t touch_state();
	uint8_t touch_type();
	int touch_coordX(int rawCoordX);
	int touch_coordY(int rawCoordY);
	int touch_getEndedXCoord();
	int touch_getEndedYCoord();
	int touch_getRawXValMax();
	int touch_getRawXValMin();
	int touch_getRawYValMax();
	int touch_getRawYValMin();
	
  private:
	void _touch_endedValueCalculation();
};
#endif 
