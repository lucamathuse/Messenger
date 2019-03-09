#include <ncurses.h>

int main(){
	int h,w;

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

	int c;
	char message[128];
	int cursorPos = 0;

	for(;;){
		c = getch();

	        wmove(win, h-2, cursorPos+2);

		if(c == 10){
			break;
		}else if(c == KEY_BACKSPACE){
			message[cursorPos] = '\0';
			mvwdelch(win, h-2, cursorPos+1);
			cursorPos -= 1;
		}else{
			message[cursorPos] = c;
		    	mvwaddch(win, h-2, cursorPos+2, message[cursorPos]);
			cursorPos += 1;
		}
		wrefresh(win);
	}

	getch();

	endwin();

	return 0;
}
