#include<iostream>
using namespace std;
int main(){
	int ref[10][10] = { 0 };
	int grid[10][10]={0};  //0 for empty - 1 for x - 2 for o 
	int n;
	do {
		cout << "enter grid dimension (3-9) \n";
		cin >> n;
	} while (n < 3 || n>9);

	// refrence for user to know 
	cout << "this is refrence for places \n";
	for (int r = 0;r < n;r++) {
		for (int c = 0;c < n;c++) {
			cout << "(" << r + 1 << "," << c + 1 << ")";
		}
		cout << endl;
	}
	cout << "this is refrence to how enter input \n";
	cout << "1 1 \nenter first number then space then second number \n";
	cout << "enjoy playing ^_^ \n";
	int rs[100], cs[100], dr[100], dc[100];            
	int verify = 0; //verify=2*n+2
	//check rows
	for (int r = 0;r < n;r++) {
		rs[verify] = r, cs[verify] = 0, dr[verify] = 0, dc[verify++] = 1;
	}

	//check col
	for (int c = 0;c < n;c++) {
		rs[verify] = 0, cs[verify] = c, dr[verify] = 1, dc[verify++] = 0;
	}
	//add diagonal 1
		rs[verify] = 0, cs[verify] = 0, dr[verify] = 1, dc[verify++] = 1;
	//add diagonal 2
		rs[verify] = 0, cs[verify] = n-1, dr[verify] = 1, dc[verify++] = -1;

		int turn = 0; //0 for x - 1 for o
		int steps = 0;

	while (true) {
		if (steps == n * n) {
			cout << "********************** tie **********************";
			return 0;
		}

		char sympol='x';
		if (turn == 1)
			sympol = 'o';

		cout << "player " << sympol << " turn . enter empty location [r,c] : \n";
		int r, c;
		cin >> r >> c;
		r -= 1; 
		c -= 1;
		if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 0) {
			cout << "invalid input try again \n";
			continue;
		}
		grid[r][c] = turn + 1;

	//print the grid
		for (int r = 0;r < n;r++) {
			for (int c = 0;c < n;c++) {
				char sym = '.';
				if (grid[r][c] == 1)
					sym = 'x';
				else if (grid[r][c] == 2)
					sym = 'o';
				cout << sym;
			}
			cout<<endl;
		}

     // check win status
		for (int check = 0;check < verify;check++) {
			int r = rs[check], c = cs[check], rd = dr[check], cd = dc[check];
			int cnt = 0, first = grid[r][c];
			if (first == 0)
				continue;
			for (int step = 0;step < n;step++, r += rd, c += cd) {
				cnt += grid[r][c] == first;
			}
			if (cnt == n) {
				cout << " ********************** player " << sympol << " won **********************" ;
				return 0;
			}
		}

		steps++;
		turn = !turn;
	}
    

	return 0;
}