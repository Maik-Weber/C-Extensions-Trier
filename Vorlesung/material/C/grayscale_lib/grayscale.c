// Grayscale Filter in C-Implementation
// size: width*height of image in pixels
// bytes: input image bytes in rgb format, will be overwritten!
void grayscale_filter(int size, unsigned char* bytes)
{
	for (int i =0; i < 3*size; i+=3)
	{
		unsigned char r = bytes[i];
		unsigned char g = bytes[i + 1];
		unsigned char b = bytes[i + 2];

		unsigned char avg = (r + g + b) / 3;

		bytes[i] = avg;
		bytes[i + 1] = avg;
		bytes[i + 2] = avg;
	}
}
