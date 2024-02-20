#include <iostream>
#include <vector>

using namespace std;

using Board = vector<vector<char>>;

void initializeBoard(Board &board) {
    board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
}

void displayBoard(const Board &board) {
    for (const auto &row : board) {
        cout << " " << row[0] << " | " << row[1] << " | " << row[2] << endl;
        cout << "-----------" << endl;
    }
}

bool makeMove(Board &board, char player, int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    cout << "Invalid move. Try again." << endl;
    return false;
}

bool checkWin(const Board &board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
           (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}

bool checkDraw(const Board &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

int main() {
    Board board;
    char currentPlayer = 'X';

    do {
        initializeBoard(board);
        bool gameWon = false;
        bool gameDraw = false;

        do {
            displayBoard(board);

            int row, col;
            do {
                cout << "Player " << currentPlayer << ", enter your move (row and column): ";
                cin >> row >> col;
            } while (!makeMove(board, currentPlayer, row, col));

            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            switchPlayer(currentPlayer);

        } while (!gameWon && !gameDraw);

        displayBoard(board);

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

    } while (playAgain());

    return 0;
}
