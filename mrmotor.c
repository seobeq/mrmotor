// This is my motor control program written in April/May 2017 by seobeq.
#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>
#include <ncurses.h>

void stop();
void turnleft();
void turnright();
int main(){
wiringPiSetup();
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(14,OUTPUT);
pinMode(30, OUTPUT);
softPwmCreate(22, 0, 100);
softPwmCreate(21, 0, 100);
int ch;
initscr();
cbreak();
keypad(stdscr, TRUE);
noecho();
start_color();
init_pair(1, COLOR_RED, COLOR_BLACK);
init_color(COLOR_RED, 100, 0 , 0);
attron(COLOR_PAIR(1));
printw("Hello, I'm Mr Motor.\n");
printw("Use the left and right arrow keys to spin me.\n");
printw("Use the up arrow to stop me spinning.\n");
printw("Use ctrl c to quit.\n");
attroff(COLOR_PAIR(1));
while(TRUE){
ch = getch();
if(ch == KEY_LEFT){
turnleft();
}
else if(ch == KEY_RIGHT){
turnright();
}
else if(ch != KEY_LEFT || KEY_RIGHT){
stop();
}
refresh();
}
//getch();
endwin();
}
void stop(){
digitalWrite(12,LOW);
digitalWrite(13,LOW);
digitalWrite(14,LOW);
digitalWrite(30,LOW);
}
void turnright(){
softPwmWrite(21,50);
softPwmWrite(22,50);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
digitalWrite(14,LOW);
digitalWrite(30,HIGH);
}
void turnleft(){
softPwmWrite(21,50);
softPwmWrite(22,50);
digitalWrite(12,LOW);
digitalWrite(13,HIGH);
digitalWrite(14,HIGH);
digitalWrite(30,LOW);
}
