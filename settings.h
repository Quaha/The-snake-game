#pragma once

const int N = 25;
const int M = 75;

const int SNAKE_START_X = M / 2;
const int SNAKE_START_Y = N / 2;

const int TURN_TIME = 50;

const char FREE_SPACE_SYMBOL = '.';
const char SNAKE_SYMBOL = '#';
const char HEAD_SYMBOL = '@';
const char APPLE_SYMBOL = '*';

//Game Files
const int FREE_SPACE_CODE = 0;
const int SNAKE_CODE = 1;
const int HEAD_CODE = 2;
const int APPLE_CODE = 3;