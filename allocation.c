/* github login ID1: ynaima
 * github login ID2: abdullahi3bdi
 * URL:  https://github.com/ynaima/CP386_Assignment4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(void)
{
    char sent[1000] = { '\0' };

    while (1) {
        //Enter Exit to stop execution:
        fgets(sent, 1000, stdin);
        if (strncmp(sent, "Exit", 4) == 0) {
            printf("You broke the loop of execution.\n");
            break;
        }
        else{
        	//firstFit(blockSize, m, processSize, n);
			//bestFit(blockSize, m, processSize, n);
			//worstFit(blockSize, m, processSize, n);
			printf("One!");
			continue;

        }
    }
    return 0;
}













