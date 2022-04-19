#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define WIDTH  100
#define HEIGHT 44

#define idx(x, y) ((x)+WIDTH*(y))

struct trail {
	float start;
	float end;
	float speed;
} trails[WIDTH];

void init_trail(struct trail *trail)
{
	trail->start = -(float)(rand() % HEIGHT);
	trail->end = 0;
	trail->speed = (rand() % 5) / 10.0f + 0.2f;
}

void update(CHAR_INFO consoleBuffer[])
{
	CHAR_INFO space = {.Char.AsciiChar=' ', .Attributes=0};

	for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++)
			consoleBuffer[idx(x, y)] = space;

		int start = trails[x].start < 0 ? 0 : (int)trails[x].start;
		int end = trails[x].end > HEIGHT ? HEIGHT : (int)trails[x].end;

		for (int y = start; y < end; y++)
			consoleBuffer[idx(x, y)] = (CHAR_INFO) {
			.Char.AsciiChar = rand() % 256,
			.Attributes = FOREGROUND_GREEN |
			(y < (int)trails[x].end-1 ? 0 :
			FOREGROUND_RED | FOREGROUND_BLUE)};

		trails[x].start += trails[x].speed;
		trails[x].end += trails[x].speed;

		if (trails[x].start >= HEIGHT)
			init_trail(&trails[x]);
	}
}

int main(void)
{
	srand((unsigned)time(NULL));

	/* Console window */
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT windowSize = {0, 0, WIDTH-1, HEIGHT-1};
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);

	COORD bufferSize = {WIDTH, HEIGHT};
	SetConsoleScreenBufferSize(wHnd, bufferSize);

	CHAR_INFO consoleBuffer[WIDTH * HEIGHT];
	COORD charBufSize = {WIDTH, HEIGHT};
	COORD characterPos = {0, 0};
	SMALL_RECT writeArea = {0, 0, WIDTH-1, HEIGHT-1};

	SetConsoleTitle(TEXT("Enter the Matrix"));

	/* Trails */
	for (int i = 0; i < WIDTH; i++)
		init_trail(&trails[i]);

	/* Matrix */
	for (;;) {
		update(consoleBuffer);
		WriteConsoleOutputA(wHnd, consoleBuffer,
				charBufSize, characterPos, &writeArea);
		Sleep(16);
	}

	return 0;
}
