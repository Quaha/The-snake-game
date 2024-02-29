#pragma once

const int FREE_SPACE_CODE = 0;
const int SNAKE_CODE = 1;
const int HEAD_CODE = 2;
const int APPLE_CODE = 3;

/*
    ____________                           
    |settings.h| ____                    
    |__________|    |   ________ 
    ____________    |-->|libs.h| 
    |gameData.h| ___|   |______| 
    |__________|            | 
                            |    ________________      ______________
                            |--> |controller.cpp| <--> |controller.h| ____
                            |    |______________|      |____________|    |
                            |         ^                                  |
                            |         |______________________            |
                            |                               |            |
                            |      ____________          __________      |      __________
                            |----> |engine.cpp| <------> |engine.h| _____|----> |main.cpp|
                            |      |__________|          |________|      |      |________|
                            |         ______________________|            |
                            |         |                                  |
                            |         V                                  |
                            |      ____________          __________      |
                            |----> |screen.cpp| <------> |screen.h| _____|
                                   |__________|          |________|
*/