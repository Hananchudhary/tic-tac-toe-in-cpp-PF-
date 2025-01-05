#include<iostream>
#include<Windows.h>
using namespace std;
const int COLS = 3;
const int ROWS = 3;
void setColor(int foreground, int background = 0) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = (background << 4) | foreground; // Combine foreground and background
	SetConsoleTextAttribute(hConsole, colorAttribute);
}
void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT |
		ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState ==

			FROM_LEFT_1ST_BUTTON_PRESSED)

		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = rpos;
	scrn.Y = cpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
bool validInput(char board[][COLS], int x, int y) {
	if ((x > ROWS || y > COLS) || (x<0||y<0)) {
		return false;
	}
	if (board[x - 1][y - 1] != 'x' && board[x - 1][y - 1] != 'o') { // x and y indexing starts from 1
		return true;
	}
	else {
		return false;
	}
}
void placement(char board[][COLS], int x, int y,int turn) { // places marks on board 2d array
	char mark;
	if (turn == 1) {
		mark = 'x';
	}
	else {
		mark = 'o';
	}
	board[x - 1][y - 1] = mark;
}
bool wincheck(char board[][COLS],int turn) {
	char mark;
	if (turn == 1) {
		mark = 'x';
	}
	else {
		mark = 'o';
	}
	int ct = 0;
	for (int i = 0;i < ROWS;i++) { // rows check for win
		ct = 0;
		for (int j = 0;j < COLS;j++) {
			if (board[i][j] == mark) {
				ct++;
			}
		}
		if (ct == 3) {
			return true;
		}
		else {
			ct = 0;
		}
	}
	for (int i = 0;i < COLS;i++) {  // column check
		ct = 0;
		for (int j = 0;j < ROWS;j++) {
			if (board[j][i] == mark) {
				ct++;
			}
		}
		if (ct == 3) {
			return true;
		}
		else {
			ct = 0;
		}
	}
	ct = 0;
	for (int i = 0;i < ROWS;i++) { // main diagonal check
		if (board[i][i] == mark) {
			ct++;
		}
	}
	if (ct == 3) {
		return true;
	}
	else {
		ct = 0;
	}
	for (int i = 0;i < ROWS;i++) { // non-principle diagonal
		if (board[i][COLS - i - 1] == mark) {
			ct++;
		}
	}
	if (ct == 3) {
		return true;
	}
	else {
		ct = 0;
	}
	return false;
}
bool AIwincheck(char board[][COLS], int& x, int& y) {
	char mark = 'o';
	int ct1 = 0;
	int ct2 = 0;
	int tempx;
	int tempy;
	for (int i = 0;i < ROWS;i++) {
		ct1 = 0;
		ct2 = 0;
		for (int j = 0;j < COLS;j++) {
			if (board[i][j] == ' ') {
				ct1++;
				tempx = i + 1;
				tempy = j + 1;
			}
			if (board[i][j] == mark) {
				ct2++;
			}
		}
		if (ct1 == 1 && ct2 == 2) {
			x = tempx;
			y = tempy;
			return true;
		}
	}
	ct1 = 0;
	ct2 = 0;
	for (int i = 0;i < ROWS;i++) {
		ct1 = 0;
		ct2 = 0;
		for (int j = 0;j < COLS;j++) {
			if (board[j][i] == ' ') {
				ct1++;
				tempx = j + 1;
				tempy = i + 1;
			}
			if (board[j][i] == mark) {
				ct2++;
			}
		}
		if (ct1 == 1 && ct2 == 2) {
			x = tempx;
			y = tempy;
			return true;
		}
	}
	ct1 = 0;
	ct2 = 0;
	for (int i = 0;i < ROWS;i++) {
		if (board[i][i] == mark) {
			ct2++;
		}
		if (board[i][i] == ' ') {
			ct1++;
			tempx = i + 1;
			tempy = i + 1;
		}
	}
	if (ct1 == 1 && ct2 == 2) {
		x = tempx;
		y = tempy;
		return true;
	}
	else {
		ct1 = 0;
		ct2 = 0;
	}
	for (int i = 0;i < ROWS;i++) {
		if (board[i][COLS - i - 1] == mark) {
			ct2++;
		}
		if (board[i][COLS - i - 1] == ' ') {
			ct1++;
			tempx = i + 1;
			tempy = COLS - i;
		}
	}
	if (ct1 == 1 && ct2 == 2) {
		x = tempx;
		y = tempy;
		return true;
	}
	else {
		ct1 = 0;
		ct2 = 0;
	}
	return false;
}
bool AIlosecheck(char board[][COLS], int& x, int& y) {
	char mark = 'x';
	int ct1 = 0;
	int ct2 = 0;
	int tempx;
	int tempy;
	for (int i = 0;i < ROWS;i++) {
		ct1 = 0;
		ct2 = 0;
		for (int j = 0;j < COLS;j++) {
			if (board[i][j] == ' ') {
				ct1++;
				tempx = i + 1;
				tempy = j + 1;
			}
			if (board[i][j] == mark) {
				ct2++;
			}
		}
		if (ct1 == 1 && ct2 == 2) {
			x = tempx;
			y = tempy;
			return true;
		}
	}
	ct1 = 0;
	ct2 = 0;
	for (int i = 0;i < ROWS;i++) {
		ct1 = 0;
		ct2 = 0;
		for (int j = 0;j < COLS;j++) {
			if (board[j][i] == ' ') {
				ct1++;
				tempx = j + 1;
				tempy = i + 1;
			}
			if (board[j][i] == mark) {
				ct2++;
			}
		}
		if (ct1 == 1 && ct2 == 2) {
			x = tempx;
			y = tempy;
			return true;
		}
	}
	ct1 = 0;
	ct2 = 0;
	for (int i = 0;i < ROWS;i++) {
		if (board[i][i] == mark) {
			ct2++;
		}
		if (board[i][i] == ' ') {
			ct1++;
			tempx = i + 1;
			tempy = i + 1;
		}
	}
	if (ct1 == 1 && ct2 == 2) {
		x = tempx;
		y = tempy;
		return true;
	}
	else {
		ct1 = 0;
		ct2 = 0;
	}
	for (int i = 0;i < ROWS;i++) {
		if (board[i][COLS - i - 1] == mark) {
			ct2++;
		}
		if (board[i][COLS - i - 1] == ' ') {
			ct1++;
			tempx = i + 1;
			tempy = COLS - i;
		}
	}
	if (ct1 == 1 && ct2 == 2) {
		x = tempx;
		y = tempy;
		return true;
	}
	else {
		ct1 = 0;
		ct2 = 0;
	}
	return false;
}
void AIrandom(char board[][COLS], int& x, int& y) {
	char mark = 'o';
	int temp = 0;
	if (board[1][1] == ' ') {
		x = 2;
		y = 2;
		return;
	}
	for (int i = 0;i < ROWS;i++) {
		for (int j = 0;j < COLS;j++) {
			if (board[i][j] == mark) {
				for (int h = i - 1;h < ROWS;h++) {
					for (int k = j - 1;k < COLS;k++) {
						if (h < ROWS && h >= 0 && k < COLS && k >= 0) {
							if (board[h][k] == ' ') {
								x = h + 1;
								y = k + 1;
								temp = 1;
								return;
							}
						}
					}
				}
			}
		}
	}
	if (temp == 0) {
		while (true) {
			x = (((x + 123) * 56) / 37) % 4;
			y = (((x + 423) * 26) / 38) % 4;
			if (validInput(board, x, y))
				return;
		}
	}
}
void AIinput(char board[][COLS], int& x, int& y) {
	if (!AIwincheck(board, x, y)) { // first checks if AI is winning than checks if it loosing if not than if centre position is empty places at it, if not than find a random position where it has advantage whether he has already a mark in that row, column or diagonal
		if (!AIlosecheck(board, x, y)) {
			AIrandom(board, x, y);
		}
	}
}
void printmenu() { // print menu to select one player or two
	char ch = 219;
	for (int i = 0;i < 5;i++) {
		gotoRowCol(35, i + 6);
		for (int j = 0;j < 50;j++) {
			setColor(255, 255);
			cout << ch;
		}
		cout << endl;
	}
	gotoRowCol(50, 8);
	setColor(0, 255);
	cout << "O N E   P L A Y E R";
	setColor(255, 255);
	for (int i = 0;i < 5;i++) {
		gotoRowCol(35, i + 15);
		for (int j = 0;j < 50;j++) {
			setColor(255, 255);
			cout << ch;
		}
		cout << endl;
	}
	gotoRowCol(50, 17);
	setColor(0, 255);
	cout << "T W O  P L A Y E R";
}
void printboard() { // print tic tac toe board
	char ch = 219;
	for (int i = 0;i < 23;i++) {
		gotoRowCol(40, i + 2);
		for (int j = 0;j < 44;j++) {
			if ((j + 1) % 15 == 0 || ((i + 1) % 8 == 0)) {
				setColor(150, 0);
			}
			else {
				setColor(255, 0);
			}
			cout << ch;
		}
		cout << endl;
	}
}
void clickLocation(int& x, int& y) { // converts the mouse click in the form of boxes of board
	int row, col, temp = 0;
	getRowColbyLeftClick(row, col);
	for (int i = 0;i < ROWS;i++) {
		if (col > (2 + (i * 8)) && col < ((i + 1) * 8)) {
			x = i + 1;
			temp++;
		}
	}
	for (int i = 0;i < COLS;i++) {
		if (row > (40 + (i * 15)) && row < (53 + (15 * i))) {
			y = i + 1;
			temp++;
		}
	}
	if (temp != 2) {
		x = 9;
		y = 9;
	}
}
void printmark1(int x, int y) { // prints cross at a specific box
	for (int i = 0;i < 6;i++) {
		gotoRowCol(40 + ((y - 1) * 15) + 4, (i + 2) + ((x - 1) * 8));
		for (int j = 0;j < 6;j++) {
			if (j == i || j == 5 - i) {
				setColor(1, 1);
				cout << "*";
			}
			else {
				setColor(255, 255);
				cout << " ";
			}
		}
		cout << endl;
	}
}
void printmark2(int x, int y) {// prints tick at a specific box
	for (int i = 0;i < 5;i++) {
		gotoRowCol(40 + ((y - 1) * 15) + 2, (i + 3) + ((x - 1) * 8));
		for (int j = 0;j < 10;j++) {
			if (j == 9 - i) {
				setColor(4, 4);

				cout << "*";
			}
			else if (j == i && i > 2) {
				setColor(4, 4);
				cout << "*";
			}
			else {
				setColor(255, 255);
				cout << " ";
			}
		}
		cout << endl;
	}
}
void printendmenu(int ct) { // print a menu to tell who won and ask to play again
	char ch = 219;
	for (int i = 0;i < 5;i++) {
		gotoRowCol(35, i + 2);
		for (int j = 0;j < 50;j++) {
			setColor(255, 255);
			cout << ch;
		}
		cout << endl;
	}
	gotoRowCol(48, 4);
	setColor(0, 255);
	if (ct == 1) {
		cout << "P L A Y E R  'x'  W I N";
	}
	else if (ct == 2) {
		cout << "P L A Y E R  'v'  W I N";
	}
	else {
		cout << "M A T C H       D R A W";
	}
	setColor(255, 255);
	for (int i = 0;i < 5;i++) {
		gotoRowCol(35, i + 10);
		for (int j = 0;j < 50;j++) {
			setColor(255, 255);
			cout << ch;
		}
		cout << endl;
	}
	gotoRowCol(53, 12);
	setColor(0, 255);
	cout << "N E W  G A M E";
	for (int i = 0;i < 5;i++) {
		gotoRowCol(35, i + 18);
		for (int j = 0;j < 50;j++) {
			setColor(255, 255);
			cout << ch;
		}
		cout << endl;
	}
	gotoRowCol(56, 20);
	setColor(0, 255);
	cout << "E X I T";
}
int main() {
	while (true) {
		int i = 1;
		int x, y, temp = 0, ct = 0;
		bool inputcheck = true;
		bool win = false, win2 = false;
		char board[ROWS][COLS] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} }; // initializes board with spaces
		setColor(0, 0);
		system("cls");
		printmenu();
		setColor(0, 0);
		while (temp == 0) {
			getRowColbyLeftClick(x, y);
			if (x >= 35 && x <= 84 && y >= 6 && y <= 10) {
				system("cls");
				printboard();
				temp = 1;
			}
			else if (x >= 35 && x <= 84 && y >= 15 && y <= 19) {
				system("cls");
				printboard();
				temp = 2;
			}
		}
		while (i <= (ROWS * COLS)) {
			if (i % 2 != 0) {
				clickLocation(x, y);
				if (!validInput(board, x, y)) {
					continue;
				}
				printmark1(x, y);
				placement(board, x, y, i % 2);
				win = wincheck(board,i%2);
				if (win) {
					ct = 1;
					break;
				}
			}
			else {
				if (temp == 1) {
					AIinput(board, x, y);
				}
				if (temp == 2) {
					clickLocation(x, y);
				}
				if (!validInput(board, x, y)) {
					continue;
				}
				placement(board, x, y, i % 2);
				printmark2(x, y);
				if (win) {
					ct = 2;
					break;
				}
			}
			i++;
		}
		setColor(0, 255);
		if (ct == 1) {
			printendmenu(ct);
		}
		else if (ct == 2) {
			printendmenu(ct);
		}
		else {
			ct = 3;
			printendmenu(ct);
		}
		while (true) {
			getRowColbyLeftClick(x, y);
			if (x >= 35 && x <= 84 && y >= 10 && y <= 14) {
				break;
			}
			else if (x >= 35 && x <= 84 && y >= 18 && y <= 22) {
				return 0;
			}
			else {
				continue;
			}
		}
	}
	return 0;
}