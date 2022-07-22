/* github login ID1: ynaima
 * github login ID2: abdullahi3bdi
 * URL:  https://github.com/ynaima/CP386_Assignment4
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct processes {
   int limit;
   float base;
   char name[30];
};
int free_memory;
int p_num = 0;  //records the number of processes


//The First fit algorithm
void firstFit(int blockSize[], int m, int processSize[], int n){
	//indicate that it is the first process requesting for memory
	if (p_num == 0){

	}

}


int main(void)
{
    char sent[500] = { '\0' };
    char p_name[200];

    int p_size;
    char algo [20];
    int init_memory;
    scanf("%d", &init_memory);

    //struct processes process_array, *ptr;

    //ptr = &process_array;
    //ptr = (struct processes*) malloc(sizeof(struct processes));

    // initializing memory block of given bytes
    //char *memory = (char*)malloc(init_memory);
    printf("Allocated %d bytes of memory\n", init_memory);

    while (1) {
    	printf("Allocator>");
        //Enter Exit to stop execution:
        scanf("%s", sent);
        if (strncmp(sent, "Exit", 4) == 0) {
            printf("You broke the loop of execution.\n");
            break;
        }
        //checking the different commands from the user
        else if (strncmp(sent, "Status", 6) == 0){
				printf("printing status\n");
        }
		else if (strncmp(sent, "C", 1) == 0){
			printf("Compaction process is successful\n");
		}

        //when releasing memory
        //when requesting for memory
        else if (strncmp(sent, "RQ", 1) == 0){
        	scanf( "%s %d %c",p_name, &p_size, algo);
        	p_num++;
        	//strcpy((ptr)->name, p_name);
        	//(ptr)->base = p_size;
        	if (strncmp(algo, "F", 1) == 0){
        		//firstFit(memory, p_size);
        		printf("Successfully allocated %d to process %s algo F\n", p_size, p_name);
        	}
        	else if (strncmp(algo, "B", 1) == 0){
        		//BestFit(memory, p_size);
        		printf("Successfully allocated %d to process %s algo B\n", p_size, p_name);
        	}
        	else{
        		//worstFit(memory, p_size);
        		printf("Successfully allocated %d to process %s, algo W\n", p_size, p_name);
        	}

        	}
        else{
        	scanf("%s", p_name);
			printf("Successfully released memory for process %s\n", p_name);
        }
    }

    return 0;
}





