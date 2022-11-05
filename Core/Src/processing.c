/*
 * processing.c
 *
 *  Created on: Nov 5, 2022
 *      Author: nguye
 */

#ifndef SRC_PROCESSING_C_
#define SRC_PROCESSING_C_
#include"global.h"

void processReset(){
		counterLed=0;
		updateLedBuffer(counterLed);
		update7SEG(FIRSTSEVENSEGMENTLED);
		timer3_flag=0;
}
void processIncrease(){
		counterLed++;
		if(counterLed>MAXIMU_VALUE) counterLed=0;
		updateLedBuffer(counterLed);
		update7SEG(FIRSTSEVENSEGMENTLED);
		timer3_flag=0;
		setTimer2(TEN_SECOND);
}
void processDecrease(){
		counterLed--;
		if(counterLed<MINIMUM_VALUE) counterLed=9;
		updateLedBuffer(counterLed);
		update7SEG(FIRSTSEVENSEGMENTLED);
		timer3_flag=0;
		setTimer2(TEN_SECOND);
}
void processAutoDecrease(){
	counterLed--;
	if(counterLed<MINIMUM_VALUE) counterLed=0;
	updateLedBuffer(counterLed);
	update7SEG(FIRSTSEVENSEGMENTLED);
	setTimer2(ONE_SECOND);
}
#endif /* SRC_PROCESSING_C_ */
