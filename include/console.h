#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#define SCR_UP      0
#define SCR_DOWN    1

#define SCREEN_SIZE		(80 * 25)
#define SCREEN_WIDTH		80

void outChar(struct Console* console, char ch);
void initScreen(struct TTY* tty);
void selectConsole(int nr);
void scrollScreen(struct Console* con, int dir);

#endif /* _CONSOLE_H_ */
