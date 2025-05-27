#include <gui/screen1_screen/Screen1View.hpp>
extern uint16_t scores;
extern uint16_t highScore;
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

void Screen1View::handleTickEvent()
{
	tickCounter += 1;
	updatePoint(scores);
	updateHighScore(highScore);

}
void Screen1View::updatePoint(int newValue)
{
    Unicode::snprintf(screen1pointBuffer, SCREEN1POINT_SIZE, "%d", newValue);
    screen1point.setWildcard(screen1pointBuffer);
    screen1point.invalidate();
}

void Screen1View::updateHighScore(int newValue)
{
    Unicode::snprintf(screen1point_1Buffer, SCREEN1POINT_SIZE, "%d", newValue);
    screen1point_1.setWildcard(screen1point_1Buffer);
    screen1point_1.invalidate();
}
