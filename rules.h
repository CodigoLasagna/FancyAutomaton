//Conway's Game of life
int select_type(int ruletype, int* grid, size_t x, size_t y, size_t height);
int select_type(int ruletype, int* grid, size_t x, size_t y, size_t height, int* rules);
int wolfram(int* grid, size_t x, size_t y, size_t height, int* rules);
int snowflake(int * grid, size_t x, size_t y, size_t height);

int GameOfLife(int* grid, size_t x, size_t y, size_t height);
int Rule30(int* grid, size_t x, size_t y, size_t height);
int Rule94(int* grid, size_t x, size_t y, size_t height);
int Rule90(int* grid, size_t x, size_t y, size_t height);

int selfImpl(int* grid, size_t x, size_t y, size_t height, int* rules);