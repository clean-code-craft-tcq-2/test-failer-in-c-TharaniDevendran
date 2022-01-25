#include <stdio.h>
#include <assert.h>

const char* MajorColorNames[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* MinorColorNames[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

void DisplayOnConsole(int Index, const char* MajorColor, const char* MinorColor)
    { 
        assert( MajorColorNames[Index / numberOfMajorColors] == MajorColor);
        assert( MinorColorNames[Index % numberOfMinorColors] == MinorColor);
     
        printf("%d | %s | %s\n", Index , MajorColor, MinorColor);  
    }

int printColorMap() 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            DisplayOnConsole(i * 5 + j , MajorColorNames[i] ,  MinorColorNames[i]);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
