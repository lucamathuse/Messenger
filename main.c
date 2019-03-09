#include <ncurses.h>

int main(){
	int h,w;

	initscr();
	getmaxyx(stdscr, h, w);

	WINDOW *win = newwin(h,w,0,0);

	noecho();


	wborder(win, ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK,ACS_BLOCK);

	for(int i = 0; i<w; i++){

		mvwaddch(win, h-3, i, ACS_BLOCK);

	}

	refresh();
	wrefresh(win);
	
	getch();

	endwin();

	return 0;
}
