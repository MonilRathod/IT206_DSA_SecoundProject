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
int id;
map<int,vector<position>>cells;

private:
int cellsize;
int rotationstate;
vector<Color> color;
};
