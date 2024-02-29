#include "libs.h"

#include "engine.h"

Snake::Snake() {
	Head = new SnakeNode;
	if (SNAKE_START_X < 0 || SNAKE_START_X >= M) {
		throw "The wrong x coordinate of the beginning of the snake!";
	}
	if (SNAKE_START_Y < 0 || SNAKE_START_Y >= N) {
		throw "The wrong y coordinate of the beginning of the snake!";
	}
	(*Head).x = SNAKE_START_X;
	(*Head).y = SNAKE_START_Y;
	Tail = Head;
}

Snake::~Snake() {
	SnakeNode* CurrNode = this->Tail;
	while (CurrNode != nullptr) {
		SnakeNode* NextNode = CurrNode->next;
		delete CurrNode;
		CurrNode = NextNode;
	}
}

char Snake::getDirection() {
	return direction;
}

void Snake::setDirection(char C) {
	if (C != 'U' && C != 'D' && C != 'L' && C != 'R') {
		throw "Wrong direction!";
	}
	direction = C;
}

void Snake::spawn(GameField &F) {
	int x = (*this).Head->x;
	int y = (*this).Head->y;
	F.field[y][x] = HEAD_CODE;
}

int Snake::move(GameField& F) {
	int x = (*this).Head->x;
	int y = (*this).Head->y;

	F.field[y][x] = SNAKE_CODE;

	if (this->direction == 'U') {
		y--;
	}
	if (this->direction == 'D') {
		y++;
	}
	if (this->direction == 'L') {
		x--;
	}
	if (this->direction == 'R') {
		x++;
	}

	if (x < 0 || x >= M || y < 0 || y >= N) return 1;

	SnakeNode* NewHead = new SnakeNode;
	NewHead->x = x;
	NewHead->y = y;
	Head->next = NewHead;
	Head = NewHead;

	if (F.field[y][x] == APPLE_CODE) {
		F.score++;
		F.field[y][x] = HEAD_CODE;
		F.spawnApple();
	}
	else {
		if (F.field[y][x] == SNAKE_CODE && !(y == Tail->y && x == Tail->x)) return 1;
		F.field[y][x] = HEAD_CODE;
		int xt = Tail->x;
		int yt = Tail->y;
		F.field[yt][xt] = FREE_SPACE_CODE;
		SnakeNode* CurrTail = Tail;
		Tail = Tail->next;
		delete CurrTail;
	}
	return 0;
}

GameField::GameField() {
	field = new int*[N];
	field[0] = new int[N * M];
	for (int i = 0; i < N; i++) {
		field[i] = field[0] + M * i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			field[i][j] = FREE_SPACE_CODE;
		}
	}
	
	spawnApple();
}

GameField::~GameField() {
	delete[] field[0];
	delete[] field;
}

int GameField::getScore() const {
	return score;
}

int GameField::getCell(int i, int j) const {
	return field[i][j];
}

void GameField::spawnApple() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == FREE_SPACE_CODE) {
				cnt++;
			}
		}
	}
	int V = rand() % cnt + 1;
	
	for (int i = 0, cnt = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == FREE_SPACE_CODE) {
				cnt++;
				if (cnt == V) {
					field[i][j] = APPLE_CODE;
					return;
				}
			}
		}
	}
}