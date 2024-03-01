// Grayscale Filter in C-Implementation
// size: width*height of image
// bytes: input image bytes in rgb format, will be overwritten!
void grayscale_filter(int size, char* bytes)
{
	for (int i =0; i < 3*size; i+=3)
	{
		char r = bytes[i];
		char g = bytes[i + 1];
		char b = bytes[i + 2];

		char avg = (r + g + b) / 3;

		bytes[i] = avg;
		bytes[i + 1] = avg;
		bytes[i + 2] = avg;
	}
}
