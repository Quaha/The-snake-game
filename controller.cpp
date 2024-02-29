#include "libs.h"
#include "engine.h"

#include "controller.h"

void startWaiting() {
	bool flag = true;
	while (flag) {
		for (int i = 0; i < 256; i++) {
			flag &= !GetAsyncKeyState(i);
		}
	}
}

char control(Snake& S) {
	if (GetAsyncKeyState('W') && S.getDirection() != 'D') {
		return 'U';
	}
	if (GetAsyncKeyState('A') && S.getDirection() != 'R') {
		return 'L';
	}
	if (GetAsyncKeyState('S') && S.getDirection() != 'U') {
		return 'D';
	}
	if (GetAsyncKeyState('D') && S.getDirection() != 'L') {
		return 'R';
	}
	return S.getDirection();
}