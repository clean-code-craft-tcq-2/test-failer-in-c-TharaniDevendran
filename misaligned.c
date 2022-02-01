#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(majorColor) / sizeof(majorColor[0]);

typedef struct {
    const char* majorColor;
    const char* minorColor;
    int pairNumber;
} ColorPair;

ColorPair GetColorFromPairNumber(int PairNumber) {
    ColorPair colorPair;
    colorPair.majorColor = majorColor[(PairNumber / numberOfMinorColors)];
    colorPair.minorColor = minorColor[(PairNumber % numberOfMinorColors)];
    colorPair.pairNumber = PairNumber;
    return colorPair;
}

void VerifyColorMapForPairNumber(int expectedpairNumber)
{
    int expectedmajorcolor_i = (pairNumber-1)/5;
	int expectedminorcolor_j = (pairNumber-1)%5;
    ColorPair TestcolorPair = GetColorFromPairNumber(pairNumber);
    asser(TestcolorPair.pairNumber == expectedpairNumber);
    assert(TestcolorPair.majorColor == majorColor[expectedmajorcolor_i]);
    assert(TestcolorPair.minorColor == minorColor[expectedminorcolor_j]);
}

void formatColorPrinter(Colorpair colorpair)
{
    printf("%d | %s | %s\n", colorpair.pairNumber, colorpair.majorColor, colorpair.minorColor);
}
int printColorMap(*ToformatColorPrinter(Colorpair))
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) {
            ToformatColorPrinter(GetColorFromPairNumber (i * 5 + j));
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap(&formatColorPrinter);
    assert(result == 25);
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++) 
        {
                       VerifyColorMapForPairNumber( i * 5 + j);
        }
    }
    printf("All is well (maybe!)\n");
    return 0;
}
