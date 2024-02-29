#include "libs.h"
#include "engine.h"

#include "screen.h"

GameScreen::GameScreen(const GameField& F) {
	output_buffer = new char[N * (M + 1)];
	game_start_time = time(0);
	update(F);
}

GameScreen::~GameScreen() {
	delete[] output_buffer;
}

void GameScreen::update(const GameField& F) {
	score = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (F.getCell(i, j) == FREE_SPACE_CODE) {
				output_buffer[i * (M + 1) + j] = FREE_SPACE_SYMBOL;
			}
			if (F.getCell(i, j) == SNAKE_CODE) {
				output_buffer[i * (M + 1) + j] = SNAKE_SYMBOL;
				score++;
			}
			if (F.getCell(i, j) == HEAD_CODE) {
				output_buffer[i * (M + 1) + j] = HEAD_SYMBOL;
			}
			if (F.getCell(i, j) == APPLE_CODE) {
				output_buffer[i * (M + 1) + j] = APPLE_SYMBOL;
			}
		}
		output_buffer[i * (M + 1) + M] = '\n';
	}
	output_buffer[(N - 1) * (M + 1) + M] = '\0';
}

void GameScreen::show() const{
	static const HANDLE ConsoleObj = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(ConsoleObj, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(ConsoleObj, &structCursorInfo);
	std::cout.flush();
	SetConsoleCursorPosition(ConsoleObj, {0, 0});

	std::cout << output_buffer << "\n";
	std::cout << "Use WASD to change direction.\n";
	std::cout << "Score: " << score << '\n';
	std::cout << "Time: " << time(0) - game_start_time << '\n';
}

void GameScreen::gameOver() const {
	std::cout << "GameOver!\n";
	Sleep(3000);
}