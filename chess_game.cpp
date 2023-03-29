#include <iostream>
#include <random>
#include <vector>

#include "matrix.hpp"

//ход фигуры
bool move_figure (Matrix<std::string>& chessboard, bool is_white, std::string command){

    size_t row_index_1, row_index_2, col_index_1, col_index_2;

    for (int i = 0; i < command.size(); i++){
        auto check_num = command[i];
        //если индекс элемента строки [0]
        if (i == 0){ 

            //temp = (кол-во строк - 1) - command[0] (остаток столбцов)
            auto temp = 'g' - check_num;

            //индекс столбца = кол-во строк - остаток столбцов - 1
            col_index_1 = 8 - temp - 1;
        }
        else if (i == 1){

            //индекс строки = char кол-во строк - char command[1]
            row_index_1 = '8' - check_num;     

            auto val = chessboard.operator()(row_index_1, col_index_1) = "--";
        }
         else if (i == 2){
            auto temp = 'g' - check_num;
            col_index_2 = 8 - temp - 1;
         }
         else if (i == 3){
            row_index_2 = '8' - check_num;
            auto val = chessboard.operator()(row_index_2, col_index_2) = "wp";
         }       
    }  

    chessboard.print();

    return is_white;
}

int main(){
    Matrix<std::string> chessboard(9, 9);

    std::string arr[] = {
        "8","br","bn","bb","bk","bq","bb","bn","br",
        "7","bp","bp","bp","bp","bp","bp","bp","bp",
        "6","--","--","--","--","--","--","--","--",
        "5","--","--","--","--","--","--","--","--",
        "4","--","--","--","--","--","--","--","--",
        "3","--","--","--","--","--","--","--","--",
        "2","wp","wp","wp","wp","wp","wp","wp","wp",
        "1","wr","wn","wb","wk","wq","wb","wn","wr",
        " " , "a ", "b ", "c " , "d ", "e ", "f ", "g ", "h "
    };

    size_t arr_size = sizeof(arr)/sizeof(arr[0]);

    chessboard.fill(arr, arr_size);
    
    chessboard.print();
    cout << endl;

    auto res = move_figure(chessboard, true, "b2b4");


    
}
