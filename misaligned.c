#include <stdio.h>
#include <assert.h>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(majorColor) / sizeof(majorColor[0]);

typedef struct {
    const char* majorColor;
    const char* minorColor;
} ColorPair;

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    colorPair.majorColor = majorColor[(pairNumber / numberOfMinorColors)];
    colorPair.minorColor = minorColor[(pairNumber % numberOfMinorColors)];
    return colorPair;
}

void VerifyNumberToPair(int pairNumber, const char* expectedMajor, const char* expectedMinor){
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void formatColorPrinter(int pairNumber, const char* MajorColor, const char* MinorColor)
{
    printf("%d | %s | %s\n", pairNumber, MajorColor, MinorColor);
}
int printColorMap() 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) {
            formatColorPrinter(i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++) 
        {
                       VerifyNumberToPair( i * 5 + j, majorColor[i], minorColor[j]);
        }
    }
    printf("All is well (maybe!)\n");
    return 0;
}
