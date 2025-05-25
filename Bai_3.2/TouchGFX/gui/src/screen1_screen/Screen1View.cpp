#include <gui/screen1_screen/Screen1View.hpp>
#include "cmsis_os.h"

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}
extern osMessageQueueId_t Queue1Handle;
void Screen1View::handleTickEvent(){
	static uint32_t prevTick = 0;
	Screen1ViewBase::handleTickEvent();
	tickCount++;
	float rad = 0;
	uint8_t res = 0;
	uint8_t count = osMessageQueueGetCount(Queue1Handle);
	if(count > 0){
		osMessageQueueGet(Queue1Handle, &res, NULL, osWaitForever);
		if(res == 'P'){
			rad = ((tickCount - prevTick) % 360) * 3.14f / 180;
			txtrHand.updateZAngle(rad);

		}
	}
	else{
		prevTick = tickCount;
	}

//	uint32_t sysTick = osKernelGetTickCount();
//	rad = (sysTick % 60000)  * 3.14f / 30000;
}

