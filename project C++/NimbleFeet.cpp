#include <iostream>
using namespace std;
const int row = 5;
const int col = 3;
//Admin privillege
void createPlayBoard(int [][col],int);
void printPlayBoard(int [][col],int);
void swap(int &a,int &b);
void changeColor(int menu[][col], int row);
void inputPosition_Color(int & ,int &, int &, int menu[][col], int row);

//User privilige

struct Player{
	string name;
	int round;
	int score;
	int color; // 0-Green, 1-Yellow, 2-Red
};
void playerInfo(Player &);
int main(){
	//Create playboard(menu) and show it
	/*int menu [row][col];
	createPlayBoard(menu,row);
	printPlayBoard(menu,row);
	changeColor(menu,row);
	printPlayBoard(menu,row);*/

	Player player1, player2, player3, player4;
	player1.name = "   Ngyten  ngoc  minh";
	
	for (int i=0; i < player1.name.length(); ++i){
		if (player1.name[i] == ' ' && player1.name[i+1] == ' '){
			player1.name[i] = player1.name[i+1];
		}
	}
	cout << player1.name;
	return 0;
}

//Admin
void changeColor(int menu[][col], int row){
	int row_pos,col_pos;
	int color;
	inputPosition_Color(row_pos,col_pos,color,menu,row);
	
	for (int j=0; j < col;++j){
		if (menu[row_pos][j] == color)
			swap(menu[row_pos][col_pos],menu[row_pos][j]);
	}
}
void inputPosition_Color(int &row_pos,int &col_pos, int &color, int menu[][col], int row){
	bool condition;
	do {
		cout << "Enter the position you want to change (row-col) (Ex:2 3): ";
		cin >> row_pos >> col_pos;
		
		condition = ((0<=row_pos && row_pos<=row) && (0<=col_pos && col_pos<=col)) ? true : false;
		if (!condition) 
			cout << "The position " << row_pos << "," << col_pos << " not in range.\n";	
	}while (!condition);
	
	do{
		cout << "Enter the color value you want to place (0-Green, 1-Yellow, 2-Red): ";
		cin >> color;
		if (color != 0 && color != 1 && color != 2) cout << "\nInvalid Color.\n";
		else if (menu[row_pos][col_pos] == color) cout << "\nDuplicate Color at that position.\n";
		
		condition = ((color == 0 || color == 1 || color == 2) && (menu[row_pos][col_pos] != color)) ? true : false;
	}while (!condition);
}
void createPlayBoard(int menu[][col], int row){
	
	  menu[0][0] = 0;
	  menu[0][1] = 1;
	  menu[0][2] = 2;
	  menu[1][0] = 1;
	  menu[1][1] = 2;
	  menu[1][2] = 0;
	  menu[2][0] = 2;
	  menu[2][1] = 1;
	  menu[2][2] = 0;
	  menu[3][0] = 0;
	  menu[3][1] = 2;
	  menu[3][2] = 1;
	  menu[4][0] = 1;
	  menu[4][1] = 2;
	  menu[4][2] = 0;
}

void printPlayBoard(int menu[][col], int row){
	for (int i=0; i < row; i++){
		for (int j=0; j < col; j++)
			cout << menu[i][j];
		cout << endl;
	}
}

void swap(int &a,int &b){
	int c;
	c = a;
	a = b;
	b = c;
}

void playerInfo(Player &player){
	cout << "What is your name? ";
	getline(cin,player.name);
	
}
