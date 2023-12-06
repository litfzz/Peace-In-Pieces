#include "ImageProcessor.h"

ImageProcessor::ImageProcessor() {}

ImageProcessor::~ImageProcessor() {}

bool ImageProcessor::loadImage(const std::string& imagePath)
{
    // Load the image using OpenCV
    m_image = cv::imread(imagePath);

    // Check if the image was loaded successfully
    if (m_image.empty())
    {
        return false;
    }

    return true;
}

void ImageProcessor::generatePuzzlePieces(int gridSize)
{
    // Clear the existing puzzle pieces
    m_puzzlePieces.clear();

    // Calculate the size of each puzzle piece
    int pieceWidth = m_image.cols / gridSize;
    int pieceHeight = m_image.rows / gridSize;

    // Generate puzzle pieces by splitting the image
    for (int row = 0; row < gridSize; row++)
    {
        for (int col = 0; col < gridSize; col++)
        {
            // Calculate the starting coordinates of the current puzzle piece
            int startX = col * pieceWidth;
            int startY = row * pieceHeight;

            // Define the region of interest for the current puzzle piece
            cv::Rect roiRect(startX, startY, pieceWidth, pieceHeight);

            // Extract the region of interest from the image
            cv::Mat puzzlePiece = m_image(roiRect).clone();

            // Store the puzzle piece in the vector
            m_puzzlePieces.push_back(puzzlePiece);
        }
    }
}