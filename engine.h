#pragma once

class Snake;
class GameField;

class Snake {
private:
	struct SnakeNode {
		int x = 0;
		int y = 0;
		SnakeNode* next = nullptr;
	};

	SnakeNode* Head = nullptr;
	SnakeNode* Tail = nullptr;

	char direction = 'U';

public:
	Snake();
	Snake(const Snake& S) = delete;
	~Snake();

	Snake& operator=(const Snake& S) = delete;

	char getDirection();
	void setDirection(char C);

	void spawn(GameField &F);
	int move(GameField& F);
};



class GameField {
	friend class Snake;
protected:
	int** field = nullptr;
public:
	GameField();
	GameField(const GameField& F) = delete;
	~GameField();

	GameField& operator=(const GameField& F) = delete;

	int getCell(int i, int j) const;
	void spawnApple();
};