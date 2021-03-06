// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <string.h>

#include <windows.h>

#include <conio.h>


using namespace std;


#define MAX 1000


struct STACK
{
	int a[MAX];		// mảng chứa hoành độ của điểm
	int b[MAX];		//Mảng chứa tung độ của điểm
	int top;		// chỉ số phần tử đỉnh đầu ngăn xếp
};

// Tạo ngăn xếp
void InitStack(STACK &s)
{
	s.top = -1;
}

// Kiểm tra ngăn xếp rỗng
int IsStackNull(STACK &s)
{
	if (s.top == -1) return 1;		// ngăn xếp rỗng
	return 0;						// ngăn xếp không rỗng
}

// Kiểm tra ngăn xếp đầy hay không
int IsStackFull(STACK &s)
{
	if (s.top == MAX - 1) return 1;		// ngăn xếp đầy
	return 0;							// ngăn xếp chưa đầy
}

// Thêm một phần tử vào ngăn xếp
void Push(STACK &s, int x, int y)
{
	if (IsStackFull(s))
		cout << "Stack is full!";
	else
	{
		s.a[s.top + 1] = x;
		s.b[s.top + 1] = y;
		s.top++;
	}
}

// Lấy thông tin ở đỉnh phần tử ngăn xếp
void Top(STACK s, int &x, int &y)
{
	x = s.a[s.top];
	y = s.b[s.top];
}

// Trích hủy phần tử ở đỉnh ngăn xếp
void Pop(STACK &s, int &x, int &y)
{
	x = s.a[s.top];
	y = s.b[s.top];
	s.top--;
}
//STACK &s;
char a[1000][1000], key;

int x, y, i, m, n, m1, n1, Select;

void beginning(STACK &s, int);

void humanVsHuman(STACK &s);

void quit();

void tutorial(STACK &s, int);

void drawTable(int);

void replay();



void Goto(int x, int y) {

	COORD spot = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), spot);

}



void TextColor(int x)

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);

}



//Noi dung game

int turn(int i = 0) {

	if (i % 2 == 0) return 1;

	else return 0;

}



char OX(int i) {

	if (turn(i) == 1) return 'O';
	else return 'X';

}



void drawOX(STACK &s, int x, int y) {//Ve X, O theo turn

	if (a[x][y] != 'X' && a[x][y] != 'O') {

		if (turn(i) == 1) TextColor(11);
		else TextColor(12);

		a[x][y] = OX(i);
		Push(s, x, y);
		cout << a[x][y];
		i += 1;

	}

}

//Chặn các đầu bàn cờ
//Không cho con trỏ ra ngoài bàn cờ

void left() {

	x -= 2;

	if (x < 13) x = 13;

}



void right() {

	x += 2;

	if (x >= 77) x = 77;

}



void up() {

	y -= 1;

	if (y < 3) y = 3;

}



void down() {

	y += 1;

	if (y >= 24) y = 24;

}



void pointer(int x, int y) {

	Goto(x, y);

	n = x; m = y;
}



void gameInfo() {

	TextColor(7);

	//Thong tin

	Goto(0, 0); cout << "<== B: Back          " << endl << "Luot thu: " << i + 1;

	//Trang tri

	cout << "     M, E: chon X/O.";

	TextColor(12); cout << "       NGUOI VOI NGUOI (PVP)";

	Goto(0, 4); TextColor(11); cout << "Nguoi Choi 1" << endl << "A,D,W,S" << endl << endl;

	cout << "Nguoi choi 2" << endl << "Phim di " << endl << "chuyen" << endl << endl;

	TextColor(10); cout << "U: Undo\n" << endl;

	TextColor(14); cout << "p/s:" << endl << "Chan hai "<<endl<<"dau " << endl;

	TextColor(12); cout << "khong"; TextColor(14); cout << " thang" << endl << endl;

	TextColor(9); cout << "R: Choi lai" << endl << "Q: Thoat" << endl;

	TextColor(10); cout << endl << "Luot: " << OX(i);

	TextColor(14); Goto(110, 11); cout << "Design by: " << endl;

	TextColor(14); Goto(110, 12); cout << "Ngo Dinh Hai \t\t 16110064 " << endl;

	TextColor(14); Goto(110, 13); cout << "Nguyen Ngoc Phuong Mai \t 16110150 " << endl;

	TextColor(7);

}



int Owin() {//Dieu kien de ben O chien thang

			//Theo hang ngang

	m1 = m; n1 = n;

	while (a[n1][m] == 'O')

		n1++;

	n1--;



	if ((a[n1][m] == 'O') && (a[n1 + 2][m] == 'O') && (a[n1 + 4][m] == 'O') 
		&& (a[n1 + 6][m] == 'O') && (a[n1 + 8][m] == 'O') 
		&& ((a[n1 + 10][m] != 'X') || (a[n1 - 2][m] != 'X'))) return 1; else

		if ((a[n1][m] == 'O') && (a[n1 - 2][m] == 'O') && (a[n1 - 4][m] == 'O') 
			&& (a[n1 - 6][m] == 'O') && (a[n1 - 8][m] == 'O') 
			&& ((a[n1 - 10][m] != 'X') || (a[n1 + 2][m] != 'X'))) return 1;

	//Theo hang doc

	m1 = m; n1 = n;

	while (a[n][m1] == 'O')

		m1++;

	m1--;



	if ((a[n][m1] == 'O') && (a[n][m1 + 1] == 'O') && (a[n][m1 + 2] == 'O') 
		&& (a[n][m1 + 3] == 'O') && (a[n][m1 + 4] == 'O') 
		&& ((a[n][m1 + 5] != 'X') || (a[n][m1 - 1] != 'X'))) return 1; else

		if ((a[n][m1] == 'O') && (a[n][m1 - 1] == 'O') && (a[n][m1 - 2] == 'O') 
			&& (a[n][m1 - 3] == 'O') && (a[n][m1 - 4] == 'O') 
			&& ((a[n][m1 - 5] != 'X') || (a[n][m1 + 1] != 'X'))) return 1;

	//Theo duong cheo 

	m1 = m; n1 = n;

	while (a[n1][m1] == 'O') {

		m1++;

		n1++;

	}

	m1--; n1--;

	if ((a[n1][m1] == 'O') && (a[n1 + 2][m1 + 1] == 'O') && (a[n1 + 4][m1 + 2] == 'O') 
		&& (a[n1 + 6][m1 + 3] == 'O') && (a[n1 + 8][m1 + 4] == 'O') 
		&& ((a[n1 + 10][m1 + 5] != 'X') || (a[n1 - 2][m1 - 1] != 'X'))) return 1; else

		if ((a[n1][m1] == 'O') && (a[n1 - 2][m1 - 1] == 'O') && (a[n1 - 4][m1 - 2] == 'O') 
			&& (a[n1 - 6][m1 - 3] == 'O') && (a[n1 - 8][m1 - 4] == 'O') 
			&& ((a[n1 - 10][m1 - 5] != 'X') || (a[n1 + 2][m1 + 1] != 'X'))) return 1;

	m1 = m; n1 = n;

	while (a[n1][m1] == 'O') {

		n1++;

		m1--;

	}

	n1--; m1++;

	if ((a[n1][m1]) == 'O' && (a[n1 + 2][m1 - 1]) == 'O' && (a[n1 + 4][m1 - 2]) == 'O' 
		&& (a[n1 + 6][m1 - 3]) == 'O' && (a[n1 + 8][m1 - 4] == 'O') 
		&& ((a[n1 + 10][m1 - 5] != 'X') || (a[n1 - 2][m1 + 1] != 'X'))) return 1; else

		if ((a[n1][m1]) == 'O' && (a[n1 - 2][m1 + 1]) == 'O' && (a[n1 - 4][m1 + 2]) == 'O' 
			&& (a[n1 - 6][m1 + 3]) == 'O' && (a[n1 - 8][m1 + 4] == 'O') 
			&& ((a[n1 - 10][m1 + 5] != 'X') || (a[n1 + 2][m1 - 1] != 'X'))) return 1;



	return 0;

}



int Xwin() { //Dieu kien de ben X chien thang

			 //THeo hang ngang

	m1 = m; n1 = n;

	while (a[n1][m] == 'X') {

		n1++;

	}

	n1--;

	//Đoạn trên nhằm mục đích dịch chuyển con trỏ đến vị trí 'O' đầu hàng để tiện
	//cho việc xét vì nếu 'O' được nhập ở giau hang se khong xet duoc

	if ((a[n1][m] == 'X') && (a[n1 + 2][m] == 'X') && (a[n1 + 4][m] == 'X') 
		&& (a[n1 + 6][m] == 'X') && (a[n1 + 8][m] == 'X') 
		&& ((a[n1 + 10][m] != 'O') || (a[n1 - 2][m] != 'O'))) return 1; else //Theo Hang ngang

		if ((a[n1][m] == 'X') && (a[n1 - 2][m] == 'X') && (a[n1 - 4][m] == 'X') 
			&& (a[n1 - 6][m] == 'X') && (a[n1 - 8][m] == 'X') 
			&& ((a[n1 - 10][m] != 'O') || (a[n1 + 2][m] != 'O'))) return 1;

	//Theo hang doc

	m1 = m; n1 = n;

	while (a[n][m1] == 'X') {

		m1++;

	}

	m1--;

	if ((a[n][m1] == 'X') && (a[n][m1 + 1] == 'X') && (a[n][m1 + 2] == 'X') 
		&& (a[n][m1 + 3] == 'X') && (a[n][m1 + 4] == 'X') 
		&& ((a[n][m1 + 5] != 'O') || (a[n][m1 - 1] != 'O'))) return 1; else //Theo Hang doc

		if ((a[n][m1] == 'X') && (a[n][m1 - 1] == 'X') && (a[n][m1 - 2] == 'X') 
			&& (a[n][m1 - 3] == 'X') && (a[n][m1 - 4] == 'X') 
			&& ((a[n][m1 - 5] != 'O') || (a[n][m1 + 1] != 'O'))) return 1;

	//Theo duong cheo chinh

	m1 = m; n1 = n;

	while (a[n1][m1] == 'X') {

		m1++; n1++;

	}

	m1--; n1--;

	if ((a[n1][m1] == 'X') && (a[n1 + 2][m1 + 1] == 'X') && (a[n1 + 4][m1 + 2] == 'X') 
		&& (a[n1 + 6][m1 + 3] == 'X') && (a[n1 + 8][m1 + 4] == 'X') 
		&& ((a[n1 + 10][m1 + 5] != 'O') || (a[n1 - 2][m1 - 1] != 'O'))) return 1; else //Theo Duong cheo chinh

		if ((a[n1][m1] == 'X') && (a[n1 - 2][m1 - 1] == 'X') && (a[n1 - 4][m1 - 2] == 'X') 
			&& (a[n1 - 6][m1 - 3] == 'X') && (a[n1 - 8][m1 - 4] == 'X') 
			&& ((a[n1 - 10][m1 - 5] != 'O') || (a[n1 + 2][m1 + 1] != 'O'))) return 1;

	//Theo duong cheo phu

	m1 = m; n1 = n;

	while (a[n1][m1] == 'X') {

		n1++; m1--;

	}

	n1--; m1++;

	if ((a[n1][m1]) == 'X' && (a[n1 + 2][m1 - 1]) == 'X' && (a[n1 + 4][m1 - 2]) == 'X' 
		&& (a[n1 + 6][m1 - 3]) == 'X' && (a[n1 + 8][m1 - 4] == 'X') 
		&& ((a[n1 + 10][m1 - 5] != 'O') || (a[n1 + 2][m1 + 1] != 'O'))) return 1; else //Theo Duong cheo phu

		if ((a[n1][m1]) == 'X' && (a[n1 - 2][m1 + 1]) == 'X' && (a[n1 - 4][m1 + 2]) == 'X' 
			&& (a[n1 - 6][m1 + 3]) == 'X' && (a[n1 - 8][m1 + 4] == 'X') 
			&& ((a[n1 - 10][m1 + 5] != 'O') || (a[n1 - 2][m1 - 1] != 'O'))) return 1;



	return 0;

}

// Hien nguoi chien thang

void win(STACK &s) {

	TextColor(12);

	if ((Owin() == 1)) {

		Goto(27, 3); TextColor(11); cout << "O chien thang. An R de choi lai. Q de quit";

		key = _getch();

		if (key == 'r' || key == 'R') replay();

		else

			if (key == 'q' || key == 'Q') quit(); else beginning(s, 50);

	}

	else

		if ((Xwin() == 1)) {

			Goto(27, 3);  TextColor(12); cout << "X Chien Thang. An R de choi lai. Q de quit";

			key = _getch();

			if (key == 'r' || key == 'R') replay();

			else

				if (key == 'q' || key == 'Q') quit(); else beginning(s, 50);

		}

	TextColor(7);

}

void Undo(STACK &s) {
	if (i <= 0) return;
	int x1, y1;
	Pop(s, x1, y1);
	//cout << x1 << endl;
	a[x1][y1] = NULL;
	Goto(x1, y1); cout << "_";
	i--;
}

void replay() { //choi lai

				//background();

	i = 0; x = 13; y = 3;

	system("cls");

	gameInfo();

	drawTable(0);

}



void keybroad(STACK &s) { //Nhan thong tin tu ban phim

	key = _getch();

	if (key == 'a' || key == 'A' || int(key == 75)) left(); else

		if (key == 'd' || key == 'D' || int(key == 77)) right(); else

			if (key == 'w' || key == 'W' || int(key == 72)) up(); else

				if (key == 's' || key == 'S' || int(key == 80)) down(); else

					if (key == 'e' || key == 'E' || key == 'm' || key == 'M') drawOX(s, n, m); else
						if (key == 'u' || key == 'U') Undo(s); else

							if (key == 'r' || key == 'R') replay();

	if (key == 'b' || key == 'B') beginning(s, 50);

}



int main() {

	// background();
	STACK s;
	InitStack(s);
	beginning(s, 100);

	return 0;

}



void beginning(STACK &s, int n) {

	system("cls");



	Goto(0, 0);

	TextColor(12);

	cout << "                  __                      " << endl

		<< "                  \\_\\     __        " << endl

		<< " _________     __________/_/        " << endl

		<< "//    ____\\   //    __   \\" << endl

		<< "\\\\   \\        \\\\   /  \\   \\" << endl

		<< " \\\\   \\        \\\\  \\   \\   \\" << endl

		<< "  \\\\   \\_____   \\\\  \\___/   \\" << endl

		<< "   \\\\________\\   \\\\ ________/" << endl

		<< "     ---------      ---------" << endl;

	TextColor(10);

	cout << endl

		<< " _________       ________     " << endl

		<< "//    ____\\     |   __   \\   " << endl

		<< "\\\\   \\          |  |  \\   \\  " << endl

		<< " \\\\   \\	        |  |___\\   \\  " << endl

		<< "  \\\\   \\_____   |   ______  \\  " << endl

		<< "   \\\\________\\  |__|      \\__\\  " << endl

		<< "     ---------  ----       ---    " << endl;

	TextColor(9);

	cout << "                 _______" << endl

		<< "                /__/ \\__\\" << endl

		<< "_____  ______    __________" << endl

		<< "\\\\   \\/ _____\\  //    __   \\" << endl

		<< " \\\\    /-----   \\\\   /  \\   \\" << endl

		<< "  \\\\   \\         \\\\  \\   \\   \\" << endl

		<< "   \\\\   \\         \\\\  \\___/   \\" << endl

		<< "    \\\\___\\         \\\\ ________/" << endl

		<< "     -----           ---------" << endl;





	TextColor(11);

	Goto(45, 10); cout << "1. CHOI" << endl;

	Sleep(n); Goto(45, 11); cout << "2. HUONG DAN" << endl;

	Sleep(n); Goto(45, 12); cout << "3. THOAT" << endl;

	Sleep(n); Goto(45, 13); cout << "Menu ";

	TextColor(14);

	Sleep(n); Goto(90, 11); cout << "Design by: " << endl;

	Sleep(n); Goto(90, 12); cout << "Ngo Dinh Hai \t\t\t 16110064" << endl;

	Sleep(n); Goto(90, 13); cout << "Nguyen Ngoc Phuong Mai \t 16110150" << endl;

	Select = _getch();

	cout << char(Select);

	Sleep(200);

	if (Select == '1') humanVsHuman(s); else

		if (Select == '2') tutorial(s, 1); else

			if (Select == '3') quit(); else beginning(s, 0);

	TextColor(7);



}



void drawTable(int n) {

	int i, j;

	TextColor(8);

	Goto(12, 2);

	for (i = 0; i <= 66; i++) {

		cout << "_"; Sleep(n);   //canh tren

	}

	for (i = 0; i <= 21; i++) {

		Goto(12, i + 3);          //canh trai

		Sleep(n);

		cout << "|";

	}

	Goto(13, 24);

	for (i = 0; i <= 64; i++) {

		cout << "_"; Sleep(n);   //canh duoi

	}



	for (i = 0; i <= 21; i++) {

		Goto(78, i + 3);		   //canh phai

		Sleep(n);

		cout << "|";

	}



	for (j = 0; j <= 21; j++) {

		for (i = 0; i <= 62; i += 2) {

			Goto(i + 14, j + 3);

			cout << "|";

		}

	}



	for (j = 0; j <= 20; j++) {

		for (i = 0; i <= 64; i += 2) {

			Goto(i + 13, j + 3);

			cout << "_";

		}

	}

}



void start(STACK &s) {

	system("cls");

	tutorial(s, 2);

	system("cls");

	drawTable(3);

}



void humanVsHuman(STACK &s) {

	start(s);


	x = n = 13; y = m = 3;

	i = 0;

	do {

		gameInfo();

		pointer(x, y);

		win(s);

		keybroad(s);

	} while (key != 'q' && key != 'Q');

	quit();

}



void tutorial(STACK &s, int k) {

	//Goto(45, 100);
	cout << endl << endl << "                  <<<           HUONG DAN           >>>" << endl << endl << endl;

	cout << "Dung";

	TextColor(12); cout << " phim di chuyen";

	TextColor(7);  cout << " va";

	TextColor(12); cout << " A,D,W,S";

	TextColor(7);  cout << " de di chuyen. Dung phim";

	TextColor(12); cout << " E";

	TextColor(7);  cout << " va";

	TextColor(12); cout << " M";

	TextColor(7);  cout << " de chon." << endl << endl << "HAVE FUN! :) " << endl;;

	TextColor(10);

	cout << "Design by: " << endl;

	cout << "Ngo Dinh Hai \t\t 16110064" << endl;

	cout << "Nguyen Ngoc Phuong Mai \t 16110150" << endl;

	system("pause");

	if (k == 1) beginning(s, 0);

}





void quit() {

	TextColor(10);

	Goto(31, 11); cout << "Xin Chao! Hen Gap lai!";

	_getch();

}
