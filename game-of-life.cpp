#include <iostream>
#include <stdlib.h>
#include <vector>


class GameBoard{
    
    private:
    std::vector<std::vector<int>> board_matrix;
    int board_rows, board_cols;

    int find_neighbours(const int ii, const int jj){
        int neighbours = 0;
        for(int i = ii -1; i <= ii+1; ++i){
            for(int j = jj - 1; j <= jj+1; ++j){
                if(i >= 0 && i < board_rows && j >= 0 && j < board_cols){
                    if(!(i == ii && j == jj)){
                        if(board_matrix[i][j] == 1){
                            neighbours++;
                        }
                    }

                }
            }
        }

        return neighbours;
    }


    public:
    GameBoard(const int rows, const int cols){
        board_matrix.resize(rows);
        for(int i = 0; i < rows; ++i){
            board_matrix[i].resize(cols);
            for(int j = 0; j < cols; ++j){
                board_matrix[i][j] = std::rand() % 2;
            }
        }
        std::vector<std::vector<int>> oard_matrix = 
                       {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


        board_matrix = oard_matrix;

        board_rows = rows;
        board_cols = cols;
        display_game();
    }


    void display_game(){
        for(int i = 0; i < board_rows; ++i){
            for(int j = 0; j < board_cols; ++j){
                if(board_matrix[i][j] == 0){
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
                
                if(board_matrix[i][j] == 0){
                    if(neighbours == 3){
                        temp_board[i][j] = 1;
                    }
                }
                // if alive
                else{
                    if(neighbours < 2 || neighbours > 3){
                        temp_board[i][j] = 0;
                    }
                }
            }
        }
        board_matrix = temp_board;
        display_game();

    }

    void run(){
        while(true){
            std::cin.get();
            iterate();
        }
    }

};

int main(){

    GameBoard gameboard(11, 38);
    gameboard.run();



    return 0;
}