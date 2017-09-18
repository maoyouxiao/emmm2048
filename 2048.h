#ifndef _GAME_H
#define _GAME_H
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

//构造接口
//操作    初始化2048
//操作前  ar指向一个2048
//操作后  2048被初始化
void EmptyGame(int (*ar)[4]);

//操作    检查2048是否可操作
//操作前  ar指向一个已初始化的2048
//操作后  若可操作返回true，否则false
bool CanMove(int (*ar)[4]);

//操作    随机为2048空余位置添加一个数
//操作前  ar指向一个已初始化的2048
//操作后  成功为2048添加一个数
void InputNumber(int (*ar)[4]);

//操作    把2048向左移动
//操作前  ar指向一个已初始化的2048
//操作后  若可以移动则成功向左移动
void TurnLeft(int (*ar)[4]);

//操作    把2048向右移动
//操作前  ar指向一个已初始化的2048
//操作后  若可以则成功移动
void TurnRight(int (*ar)[4]);

//操作    把2048向上移动
//操作前  ar指向一个已初始化的2048
//操作后  若可以则成功移动
void TurnUp(int (*ar)[4]);

//操作    把2048向下移动
//操作前  ar指向一个已初始化的2048
//操作后  若可以则成功移动
void TurnDown(int (*ar)[4]);

//操作    显示2048界面
//操作前  ar指向一个已初始化的2048
//操作后  显示出2048界面
void StartGame(int (*ar)[4]);

#endif
