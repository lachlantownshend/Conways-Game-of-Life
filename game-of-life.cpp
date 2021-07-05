#include <iostream>
#include <stdlib.h>
#include <vector>

#define STARTING_GRID {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

#define DEAD 0
#define ALIVE 1

class GameBoard{
    
    private:
    std::vector<std::vector<int>> board_matrix;
    int board_rows, board_cols;

    // Find the amount of neighbours. A neighbour is a position one off in any direction (diagonal included)
    // within the bounds of the grid
    int find_neighbours(const int ii, const int jj){
        int neighbours = 0;
        for(int i = ii - 1; i <= ii + 1; ++i){
            for(int j = jj - 1; j <= jj+1; ++j){
                if(i >= 0 && i < board_rows && j >= 0 && j < board_cols){
                    if(!(i == ii && j == jj)){
                        if(board_matrix[i][j] == ALIVE){
                            neighbours++;
                        }
                    }

                }
            }
        }

        return neighbours;
    }


    public:
    GameBoard(const int rows, const int cols, const bool rnd){

        // If random desired, set all positions to either 0 or 1
        if(rnd){
            board_matrix.resize(rows);
            for(int i = 0; i < rows; ++i){
                board_matrix[i].resize(cols);
                    for(int j = 0; j < cols; ++j){
                        board_matrix[i][j] = std::rand() % 2;
                    }
                }
        }
        else{
            board_matrix = STARTING_GRID
        }
        board_rows = rows;
        board_cols = cols;
        display_game();
    }


    void display_game(){
        for(int i = 0; i < board_rows; ++i){
            for(int j = 0; j < board_cols; ++j){
                if(board_matrix[i][j] == DEAD){
                    std::cout << "." << " ";
                }
                else{
                    std::cout << "O" << " ";
                }
            }
            std::cout << "\n";
        }
    }

    void iterate(){
        std::vector<std::vector<int>> temp_board = board_matrix;

        for(int i = 0; i < board_rows; ++i){
            for(int j = 0; j < board_cols; ++j){
                int neighbours = find_neighbours(i, j);
                
                // If the position is dead and has exactly 3 neighbours, bring it back to life
                if(board_matrix[i][j] == DEAD){
                    if(neighbours == 3){
                        temp_board[i][j] = ALIVE;
                    }
                }
                // If the position is alive and doesn't have 2 or 3 neighbours, make it dead
                else{
                    if(neighbours < 2 || neighbours > 3){
                        temp_board[i][j] = DEAD;
                    }
                }
            }
        }
        board_matrix = temp_board;
        display_game();

    }

    // Continually iterate the program each time enter is hit.
    void run(){
        while(true){
            std::cin.get();
            iterate();
        }
    }

};

int main(){

    GameBoard gameboard(11, 38, false);
    gameboard.run();
    return 0;
}