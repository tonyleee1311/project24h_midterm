/*
 * fsm_simple.c
 *
 *  Created on: Nov 5, 2022
 *      Author: nguye
 */
#include"fsm_simple.h"
void fsm_simple_buttons_run(){
	switch(status){
	case INIT:
		if(timer3_flag==1){
			status=RESET;
			setTimer3(100);
		}
		break;
	case RESET:
		if(timer3_flag==1) processReset();
		if(isButtonPressed(FIRST_BUTTON)){
			status=RESET;
			setTimer3(100);
		}
		if(isButtonPressed(SECOND_BUTTON)){
			status=INC;
			setTimer3(100);
		}
		if(isButtonPressed(THIRD_BUTTON)){
			status=DEC;
			setTimer3(100);
		}
		break;
	case INC:
		if(timer2_flag==1){
			status= AUTODECREASE;
			setTimer2(100);
		}
		if(timer3_flag==1) processIncrease();
		if(isButtonPressed(FIRST_BUTTON)){
			status=RESET;
			setTimer3(100);
		}
		if(isButtonPressed(SECOND_BUTTON)){
			status=INC;
			setTimer3(100);
		}
		if(isButtonPressed(THIRD_BUTTON)){
			status=DEC;
			setTimer3(100);
		}
		if(isButtonPressedMoreThan3s(SECOND_BUTTON)){
			status=INC;
			setTimer3(100);
		}
		break;
	case DEC:
		if(timer2_flag==1){
			status= AUTODECREASE;
			setTimer2(100);
		}
		if(timer3_flag==1) processDecrease();
		if(isButtonPressed(FIRST_BUTTON)){
			status=RESET;
			setTimer3(100);
		}
		if(isButtonPressed(SECOND_BUTTON)){
			status=INC;
			setTimer3(100);
		}
		if(isButtonPressed(THIRD_BUTTON)){
			status=DEC;
			setTimer3(100);
		}
		if(isButtonPressedMoreThan3s(THIRD_BUTTON)){
			status=DEC;
			setTimer3(100);
		}
		break;
	case AUTODECREASE:
		if(timer2_flag==1) processAutoDecrease();
		if(isButtonPressed(SECOND_BUTTON)){
			status=INC;
			setTimer3(100);
		}
		if(isButtonPressed(THIRD_BUTTON)){
			status=DEC;
			setTimer3(100);
		}
		break;
	default:
		break;
	}
}
