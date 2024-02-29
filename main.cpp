#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char player;
public:
    TicTacToe() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        player = 'O';
    }

    void draw_Playing_Board() {
        cout << "-------------\n";
        for (int i = 0; i < 3; i++) {
            cout << "| ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " | ";
            }
            cout << "\n-------------\n";
        }
    }

    bool check_If_Player_Wins() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;
        return false;
    }

    void playGame() {
        int row, col;
        int turn;
        cout << "Welcome to Tic-Tac-Toe Game!\n";
        for (turn = 0; turn < 9; turn++) {
            draw_Playing_Board();
            while (true) {
                cout << "Player " << player << ", enter row (0-2) and column (0-2): ";
                cin >> row >> col;
                if (board[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2) {
                    cout << "Invalid move. Try again.\n";
                } else {
                    break;
                }
            }
            board[row][col] = player;
            if (check_If_Player_Wins()) {
                draw_Playing_Board();
                cout << "Player " << player << " wins!\n";
                break;
            }
            player = (player == 'X') ? 'O' : 'X';
        }
        draw_Playing_Board();
        if (turn == 9 && !check_If_Player_Wins()) {
            cout << "It's a draw!\nBetter luck next time!\n";
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
