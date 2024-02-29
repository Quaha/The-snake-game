#include "engine.h"
#include "screen.h"
#include "controller.h"

int main() {

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
	}
	Screen.gameOver();
	return 0;
}