// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   menu.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ddehtyar <ddehtyar@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 12:47:26 by ddehtyar          #+#    #+#             //
//   Updated: 2018/10/07 12:47:27 by ddehtyar         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include "menu.hpp"

#include "general.hpp"

menu::menu() {

	del = 110000;
	pos = 0;

	//system("printf '\e[8;40;130t'");
	write(1, "\e[8;40;130t", 11);
	int maxheight, maxwidth;
	initscr();
	getmaxyx(stdscr, maxheight, maxwidth);
	maxheight = 40;
	maxwidth = 130;
	char oldalchar = (char)219;
	curs_set(0);
	refresh();
	noecho();
	heightw = 40;
	widthw = 130;
	win = newwin(heightw, widthw, STARHEIGHT, STARWIDTH);
	cbreak();
	keypad(win, true);
	nodelay(win, true);
	for (int i = STARWIDTH; i < maxwidth - 1 - STARWIDTH; i++) {
		move(STARWIDTH, i);
		waddch(win, oldalchar);
	}
	x = 10;
	y = 2;
	point = " <<<***>>>";
	const char *mesa = " ______ _______       _____  ______ _______ _____   ____";
	const char *mesb = "|  ____|__   __|     |  __ \\|  ____|__   __|  __ \\ / __ \\";
	const char *mesc = "| |__     | |        | |__) | |__     | |  | |__) | |  | |";
	const char *mesd = "|  __|    | |        |  _  /|  __|    | |  |  _  /| |  | |";
	const char *mese = "| |       | |        | | \\ \\| |____   | |  | | \\ \\| |__| |";
	const char *mesf = "|_|       |_|        |_|  \\_\\______|  |_|  |_|  \\_\\_____/ ";
	const char *mesg = "            ______ ______ ";
	const char *mesh = "           |______|______|  ";
 	const char *meha = " _  _______    __     ___ ______  _______";
	const char *mehb = "||\\ |||  ||    ||    // \\// \\||\\ //||| ";
	const char *mehc = "|| \\|||==\\\\ /\\ //   (( __||=||| \\/ |||==";
	const char *mehd = "|| \\|||___\\V/\\V/     \\\\_||| |||    |||___";
	const char *mrha = " ___  ______ ___  ";
	const char *mrhb = " |||\\ |||   // \\\\ ";
	const char *mrhc = " |||\\\\|||==((   ))";
	const char *mrhd = " ||| \\|||   \\\\_//";
	const char *rrha = " ____   _______";
	const char *rrhb = " ||  \\\\ //| || |";
	const char *rrhc = " ||== )X(|| ||  ";
	const char *rrhd = " ||__// \\\\| ||  ";
	mvwprintw(win, y, x, mesa);
	mvwprintw(win, y + 1, x, mesb);
	mvwprintw(win, y + 2, x, mesc);
	mvwprintw(win, y + 3, x, mesd);
	mvwprintw(win, y + 4, x, mese);
	mvwprintw(win, y + 5, x, mesf);
	mvwprintw(win, y + 6, x, mesg);
	mvwprintw(win, y + 7, x, mesh);
	mvwprintw(win, y + 12, x, meha);
	mvwprintw(win, y + 13, x, mehb);
	mvwprintw(win, y + 14, x, mehc);
	mvwprintw(win, y + 15, x, mehd);
	mvwprintw(win, y + 17, x, mrha);
	mvwprintw(win, y + 18, x, mrhb);
	mvwprintw(win, y + 19, x, mrhc);
	mvwprintw(win, y + 20, x, mrhd);
	mvwprintw(win, y + 22, x, rrha);
	mvwprintw(win, y + 23, x, rrhb);
	mvwprintw(win, y + 24, x, rrhc);
	mvwprintw(win, y + 25, x, rrhd);
	posx = x + 50;
	posy = y + 14;
	wrefresh(win);
}

menu::~menu() {

	delwin(win);
	endwin();
};


void menu::moves() {

	int tmp = wgetch(win);
	switch(tmp)
	{
		case KEY_UP:
			if (pos > 0) {
				posyb = posy;
				mvwprintw(win, posy, posx, "             ");
				posy -= 5;
				pos -= 1;
			}
		 	break ;
		case KEY_DOWN:
			if (pos != 2) {
				posyb = posy;
				mvwprintw(win, posy, posx, "              ");
				posy += 5;
				pos += 1;
			}
		 	break ;
		case ' ' :
	  		posb = pos;
	  		pos = 3;
		  	break ;
	}
	if (pos == 0 || pos == 1 || pos == 2)
		mvwprintw(win, posy, posx, point);
	 wrefresh(win);
}

void menu::info() {

	int tmp;

 	const char *ray = "\n"
	"                              To save humanity, you must destroy the prativniya ships.\n"
 	"                                   and score as many points as possible.\n"
    "                                         In your dispensation:\n"
    "                                  Direction keys and shooting with the key space!\n"
    "                                 And remember that all of humanity depends on you.\n";

	while (1) {
		mvwprintw(win, y + 28, x, ray);
		wrefresh(win);
		tmp = wgetch(win);
		if (tmp == ' ') {
			const char *clean = "\n"
			"                                                                                        \n"
			"                                                                                        \n"
			"                                                                                        \n"
			"                                                                                        \n"
			"                                                                                        \n";
			mvwprintw(win, y + 28, x, clean);
			break ;
    	}
 	}
 }

int menu::start() {

	const char *bay = "\n"
"                      _______ _______ _______ ______      ______\n"
"                     (  ____ (  ___  |  ___  |  __  \\    (  ___ \\|\\     /|\\     /|\n"
"                     | (    \\/ (   ) | (   ) | (  \\  (   | (   ) ) )   ( ( \\   / )\n"
"                     | |     | |   | | |   | | |   ) |   | (__/ /| |   | |\\ (_) /\n"
"                     | | ____| |   | | |   | | |   | |   |  __ ( | |   | | \\   /\n"
"                     | | \\_  ) |   | | |   | | |   ) |   | (  \\ \\| |   | |  ) (\n"
"                     | (___) | (___) | (___) | (__/  )   | )___) ) (___) |  | |\n"
"                     (_______|_______|_______|______/    |/ \\___/(_______)  \\_/\n";

	while(1)
	{
		if (pos == 3 && posb != 1)
			break ;
		else if (pos == 3 && posb == 1) {
			info();
			pos = posb;
		}
		moves();
		usleep(del);
	}
	if (pos == 0)
	{
		delwin(win);
		endwin();
		return (1);
	}
	if (posb == 2) {
		wclear(win);
		mvwprintw(win, y, x, bay);
		wrefresh(win);
		usleep(1000000);
		return (0) ;
	}
	delwin(win);
	return (1);
}
