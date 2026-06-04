#include "game.h"

GuessGame::GuessGame(){
	reset();
}

void GuessGame::reset(){
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1,100);
	target_num = dis(gen);
	count = 0;
}

int GuessGame::getCount(){
	return count;
}

int GuessGame::check(int num){
	count++;
	if(num == target_num) return 0;
	else if(num > target_num) return 1;
	else return -1;
}
