#include "libs.h"

#include "engine.h"
#include "screen.h"
#include "controller.h"

int main() {

	srand(time(0));

	GameField Field;
	GameScreen Screen(Field);
	Snake Serpent;
	Serpent.spawn(Field);

	Screen.update(Field);
	Screen.show();

	startWaiting();

	while (true) {
		Screen.update(Field);
		Screen.show();

		Serpent.setDirection(control(Serpent));
		if (Serpent.move(Field)) break;
		Sleep(TURN_TIME);
	}
	Screen.gameOver();
	Sleep(3000);
	return 0;
}