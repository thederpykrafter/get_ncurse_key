#include <curses.h>

int main() {
	int ch;

	initscr();
	raw();
	keypad(stdscr, true); // enable extra keys
	noecho();

	printw("Type any character to see it printed bold\n");

	while (true) {
		ch = getch();

		if (ch == 113) { // q
			refresh();
			endwin();
			return 0;

		} else {
			printw("Keycode: ");
			attron(A_BOLD);
			printw("%d\n", ch);
			attroff(A_BOLD);
		}
	}
	refresh();
	getch();
	endwin();

	return 0;
}
