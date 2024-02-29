#pragma once

#include "engine.h"

class GameScreen {
private:
	char* output_buffer = nullptr;
	int game_start_time = 0;
	int score = 0;
public:

	GameScreen(const GameField& F);
	GameScreen(const GameScreen& S) = delete;
	~GameScreen();

	GameScreen& operator=(const GameScreen& S) = delete;

	void update(const GameField& F);
	void show() const;
	void gameOver() const;

};