#ifndef IMAGE_PROCESSOR_H
#define IMAGE_PROCESSOR_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class ImageProcessor
{
public:
    ImageProcessor();
    ~ImageProcessor();

    /**
     * @brief Loads an image from the specified file path.
     * @param imagePath The path to the image file.
     * @return True if the image is successfully loaded, false otherwise.
     */
    bool loadImage(const std::string& imagePath);

    /**
     * @brief Generates puzzle pieces from the loaded image.
     * @param gridSize The size of the grid to divide the image into.
     */
    void generatePuzzlePieces(int gridSize);

private:
    cv::Mat m_image;                     // The loaded image
    std::vector<cv::Mat> m_puzzlePieces; // The generated puzzle pieces
};

#endif // IMAGE_PROCESSOR_H