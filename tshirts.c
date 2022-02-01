#include <stdio.h>
#include <assert.h>

char Shirtsize(int SizeInCms) {
    char sizeName = '\0';
    if(SizeInCms >= 36 && SizeInCms < 38) 
    {
        sizeName = 'S';
    } 
    else if(SizeInCms >= 38 && SizeInCms <= 42) 
    {
        sizeName = 'M';
    } 
    else if(SizeInCms > 42 && SizeInCms<=44) 
    {
        sizeName = 'L';
    }
    else
    {
        sizeName = '\0';
    }
    return sizeName;
}
void VerifyShirtSize(int size, char sizename)
{
    assert(Shirtsize(size) == sizename);
}

int main()
{
    VerifyShirtSize(35, '\0');
    VerifyShirtSize(37, 'S');
    VerifyShirtSize(40, 'M');
    VerifyShirtSize(43, 'L');
    VerifyShirtSize(38, 'M');
    VerifyShirtSize(42, 'M');
    VerifyShirtSize(45, '\0');
    printf("All is well (maybe!)\n");
    return 0;
}
