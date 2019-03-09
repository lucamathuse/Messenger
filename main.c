#include <ncurses.h>
#include "setup.c"
#include "./src/write.c"
#include "./src/read.c"

int main(){
	int h,w;
	int c;
	char message[128];
	int cursorPos = 0;	

	initscr();
	getmaxyx(stdscr, h, w);

	WINDOW *win = newwin(h,w,0,0);

	noecho();
	keypad(stdscr, TRUE);

	wborder(win, ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK);

	for(int i = 0; i<w; i++){
		mvwaddch(win, h-3, i, ACS_BLOCK);

	}
	refresh();
	wrefresh(win);


	for(;;){
		c = getch();
		

	        wmove(win, h-2, cursorPos+2);

		if(c == 10){
			write(message);
			for(int i = 1; i<w-1; i++){
				mvwaddch(win, h-2, i, ' ');
			}
			for (int i = 0; i < sizeof(message); i++) {
				message[i] = '\0';
			}
			cursorPos = 0;
		}else if(c == 127){
			message[cursorPos] = '\0';
			mvwdelch(win, h-2, cursorPos+1);
			cursorPos -= 1;
		}
		else{
			message[cursorPos] = c;
		    	mvwaddch(win, h-2, cursorPos+2, message[cursorPos]);
			cursorPos += 1;
		}
		wrefresh(win);

	}

	endwin();

	return 0;
}
