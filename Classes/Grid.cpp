#include "Grid.h"

Grid::Grid(int rows, int columns)
    : m_rows(rows), m_columns(columns)
{
    // Initialize the grid with empty puzzle pieces
    m_grid.resize(rows, std::vector<PuzzlePiece>(columns));
}

Grid::~Grid() {}

void Grid::addPiece(const PuzzlePiece& piece, int row, int column)
{
    // Check if the provided row and column are within the grid boundaries
    if (row >= 0 && row < m_rows && column >= 0 && column < m_columns)
    {
        // Add the puzzle piece to the specified position in the grid
        m_grid[row][column] = piece;
    }
}

PuzzlePiece& Grid::getPiece(int row, int column)
{
    // Check if the provided row and column are within the grid boundaries
    if (row >= 0 && row < m_rows && column >= 0 && column < m_columns)
    {
        // Return the puzzle piece at the specified position in the grid
        return m_grid[row][column];
    }
    // If the provided row and column are out of bounds, return a default puzzle piece or handle the error as needed
    // You can throw an exception, return a default piece, or handle the error in any other appropriate way for your application
    // For simplicity, let's return a default piece here
    static PuzzlePiece defaultPiece(cv::Mat()); // Assuming you have a default constructor for PuzzlePiece
    return defaultPiece;
}
