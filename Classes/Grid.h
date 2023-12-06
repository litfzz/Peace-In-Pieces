#ifndef GRID_H
#define GRID_H

#include <vector>
#include "PuzzlePiece.h"

class Grid {
public:
    /**
     * @brief Constructs a Grid object with the specified number of rows and columns.
     * @param rows The number of rows in the grid.
     * @param columns The number of columns in the grid.
     */
    Grid(int rows, int columns);

    /**
     * @brief Destructor for the Grid object.
     */
    ~Grid();

    /**
     * @brief Adds a puzzle piece to the specified position in the grid.
     * @param piece The puzzle piece to add.
     * @param row The row index of the position.
     * @param column The column index of the position.
     */
    void addPiece(const PuzzlePiece& piece, int row, int column);

    /**
     * @brief Retrieves the puzzle piece at the specified position in the grid.
     * @param row The row index of the position.
     * @param column The column index of the position.
     * @return A reference to the puzzle piece at the specified position.
     */
    PuzzlePiece& getPiece(int row, int column);

private:
    int m_rows; // The number of rows in the grid.
    int m_columns; // The number of columns in the grid.
    std::vector<std::vector<PuzzlePiece>> m_grid; // The grid of puzzle pieces.
};

#endif // GRID_H