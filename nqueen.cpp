#include<iostream>
#include<string>
#include<vector>

using namespace std;
int boardcnt = 0;

bool IsBoardOk (vector<string>& chessboard, int row, int col) {

   // Check if there is a queen 'Q' positioned to the left of column col 
   // on the same row.
   for (int c=0; c<col; c++) {
      if (chessboard[row][c] == 'Q') {
         return false;
      }
   }

   // Check if there is queen 'Q' positioned on the upper left diagonal
   for (int r=row-1, c=col-1; r >= 0 && c >= 0; r--, c--) {
      if (chessboard[r][c] == 'Q') {
         return false;
      }
   }

   // Check if there is queen 'Q' positioned on the lower left diagonal
   for (int r=row+1, c=col-1; c >= 0 && r<chessboard.size(); r++, c--) {
      if (chessboard[r][c] == 'Q') {
         return false;
      }
   }

   return true;
}

void DisplayBoard (vector<string>& chessboard) {
   for (auto& row : chessboard) {
       for(auto& ch : row) {
           cout << ch << " ";
       } cout << endl;
   }
}


void PlaceNQueens (vector<string>& chessboard, int col) {

    // If all the columns have a queen 'Q', a solution has been found.
    if (col >= chessboard.size()) {
        cout << endl << "Board " << ++boardcnt << endl;
        cout << "========================" << endl;
        DisplayBoard(chessboard);
        cout << "========================" << endl;

    }  else {

        // Else try placing the queen on each row of the column and check if the chessboard remains OK.
        for (int row=0; row<chessboard.size(); row++) {

            chessboard[row][col] = 'Q';

            if (IsBoardOk(chessboard, row, col) == true) {
                //Chess board was OK, hence try placing the queen 'Q' in the next column.
                PlaceNQueens(chessboard, col + 1);
            }

            chessboard[row][col] = '.'; // As previously placed queen was not valid, restore '.'
        }
    }
}

int main() {

   vector<string> chessboard;
   int N;

   cout << "Enter chessboard size : ";
   cin >> N;

   for(int i=0; i<N; i++) {
       string row(".", N);
       chessboard.push_back(row);
   }

   // Start placing the queen 'Q' from the 0'th column.
   PlaceNQueens(chessboard, 0);

   return 0;
}
