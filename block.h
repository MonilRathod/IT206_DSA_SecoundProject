#pragma oncce
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;


class block
{
public:
block();
void draw();
void move(int row, int colum);
vector<position> getcellposition();
int id;
map<int,vector<position>>cells;
void rotate();
void undurotation();

private:
int cellsize;
int rotationstate;
vector<Color> color;
int rowoffset;
int columoffset;
};
