#include "colors.h"
#include <vector>

using namespace std;

const Color lightskyblue = { 167, 206, 240, 255 };
const Color yello = { 255, 255, 0, 255 };
const Color green = { 0, 255, 0, 255 };
const Color purple = { 128, 0, 128, 255 };
const Color red = { 255, 0, 0, 255 };
const Color orange = { 255, 165, 0, 255 };
const Color pink = { 255, 192, 203, 255 };
const Color blue = { 0, 0, 255, 255 };
const Color lightgray = { 111,133,151, 255 };

vector<Color> getcellcolors()
{
    return { lightskyblue, yello, green, purple, red, orange, pink, blue };
}


