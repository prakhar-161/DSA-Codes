// Leetcode Problem
/*
    Write a program to solve a Sudoku puzzle by filling the empty cells.

    A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    The '.' character indicates empty cells.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool solve(vector<vector<int>> &board) {
        for(int i=0; i < board.size(); i++) {
            for(int j=0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    for(char c = '1'; c < '9'; c++) {
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if(solve(board) == true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<int>> &board, int row, int col, char c) {
        for(int i=0; i<9; i++) {
            if(board[i][col] == c) {
                return false;
            }
            if(board[row][i] == c) {
                return false;
            }
            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == c) {
                return false;
            }
        }
        return true;
    }
};