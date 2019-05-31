#ifndef POWERBALLTICKET_H
#define POWERBALLTICKET_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <ostream>


class PowerBallTicket
{
public:
	PowerBallTicket(int wBall1,int wBall2,int wBall3,int wBall4,int wBall5,int redBall);
	PowerBallTicket(); 
	int getwhiteBall(int getNum);
	void setwhiteBall(int setNum, int loop);
	void setredBall(int setNum);
	int getredBall(); 
	int WinningTicket(PowerBallTicket& newTicket);
	friend std::ostream& operator << (std::ostream& os, const PowerBallTicket& ticket);
	

private:
	int whiteBall[5];
	int redBall;

};

char checkChoice(char* input); 

#endif