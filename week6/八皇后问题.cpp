#include<iostream>
using namespace std;
const int max_board = 30;
class Queens {
public:
    Queens(int size);
    bool is_solved() const;
    void print() const;
    bool unguarded(int col) const;
    void insert(int col);
    void remove(int col);
    int board_size; // dimension of board = maximum number of queens
private:
    int count; // current number of queens = first unoccupied row
    bool queen_square[max_board][max_board];
};
Queens::Queens(int size)
/*
Post: The Queens object is set up as an empty
configuration on a chessboard with size squares in
each row and column.
*/
{
    board_size = size;
    count = 0;
    for (int row = 0; row < board_size; row++)
        for (int col = 0; col < board_size; col++)
            queen_square[row][col] = false;
}
void Queens::print() const
{
    int row, col;
    for (row = 0; row < board_size-1; row++) {
        for (col = 0; col < board_size; col++)
            if (queen_square[row][col])
                cout << col+1 << " ";
    }
    for (col = 0; col < board_size; col++) {
        if (queen_square[row][col]) cout << col + 1;
    }
    cout << endl;
}
bool Queens::unguarded(int col) const
/*
Post: Returns true or false according as the square in the first
unoccupied row (row count) and column col is not guarded
by any queen.
*/
{
    int i;
    bool ok = true; // turns false if we find a queen in column or diagonal
    for (i = 0; ok && i < count; i++)
        ok = !queen_square[i][col]; // Check upper part of column
    for (i = 1; ok && count - i >= 0 && col - i >= 0; i++)
        ok = !queen_square[count - i][col - i]; // Check upper-left diagonal
    for (i = 1; ok && count - i >= 0 && col + i < board_size; i++)
        ok = !queen_square[count - i][col + i]; // Check upper-right diagonal
    return ok;
}
void Queens::insert(int col)
/*
Pre: The square in the first unoccupied row (row count) and column col
is not guarded by any queen.
Post: A queen has been inserted into the square at row count and column
col; count has been incremented by 1.
*/
{
    queen_square[count++][col] = true;
}
void Queens::remove(int col)
/*
Pre: There is a queen in the square in row count - 1 and column col.
Post: The above queen has been removed; count has been decremented by 1.
*/
{
    queen_square[--count][col] = false;
}
void print_information()
{
    cout << "This program determines all the ways to place n queens\n"
        << "on an n by n chessboard, where n <= " << max_board << endl;
}
bool Queens::is_solved() const
/*
Post: Returns true if the number of queens
already placed equals board_size, otherwise return false.
*/
{
    if (count == board_size) return true;
    else return false;
}
void solve_from(Queens &configuration)
{
    if (configuration.is_solved()) configuration.print();
    else
        for (int col = 0; col < configuration.board_size; col++)
            if (configuration.unguarded(col)) {
                configuration.insert(col);
                solve_from(configuration); // Recursively continue.
                configuration.remove(col);
            }
}
int main() {
    Queens configuration(8);
    solve_from(configuration);
}                                 