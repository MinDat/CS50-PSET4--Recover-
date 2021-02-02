#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define block   512
int main(int argc, char *argv[])
{
    // Open
    FILE *file = fopen( "card.raw", "r");
    FILE *img;
    unsigned char bytes[block];
    int file_count = 0;
    while ( fread(bytes, block, 1, file)) {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xE0)
        {
            file_count++;
            printf("Found %d\n", file_count);

            // create new file
            char makefile[8];

            //Write data to files
            //
            if ( file_count == 1) {
                //TODO
                sprintf(makefile, "%03i.jpg", file_count);

            } else {
                //TODO
                fclose(img);
                sprintf(makefile, "%03i.jpg", file_count);
            }
            img = fopen( makefile, "w");
            fwrite(bytes ,block , sizeof(char), img);

        } else if ( file_count > 0) {
            //TODO
            fwrite(bytes ,block , sizeof(char), img);
        }

    }
    // Close
    fclose(img);
    fclose(file);

}
