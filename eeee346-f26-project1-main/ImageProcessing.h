// You don't have to modify this file

#ifndef IMAGE_PROCESSING__ // header guard: to avoid the problem of multiple inclusion
#define IMAGE_PROCESSING__

/*
 * Enhances the contrast of the original image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void histogramStretching(int **oData, int **rData, int height, int width);

/*
 * Compresses the original image and generates a reconstructed image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void btc(int **oData, int **rData, int height, int width);

/*
 * Detects edges in the original image.
 *
 * @oData - original input 2D array
 * @rData - output 2D array
 * @height - height of 2D arrays
 * @width - width of 2D arrays
 */
void edgeDetect(int **oData, int **rData, int height, int width);

#endif
