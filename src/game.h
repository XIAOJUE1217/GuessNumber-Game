#ifndef GAME_H
#define GAME_H
#include <random>

class GuessGame {
private:
	int target_num;
	int count;
public:
	GuessGame();
	void reset();
	int getCount();
	//返回：0猜对，1猜大，-1猜小
	int check(int num);
};
#endif
