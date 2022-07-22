#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define MAX 1048576
#define MAX_PID 100

struct Node *head_node;
struct Node *blk_of_space;
struct Node *temp_node;

char reqst[3];
char pr[3];
char alg_type[2];
int lastAddress;
int space_rqstd;
struct Node
{
    int free_space;
    int starting_pointer;
    int ending_pointer;
    struct Node *nxt;
    char pr_id[MAX_PID];
};

void f_fit(char pr_id[3], int space_rqstd)
{
    temp_node = head_node;
    // int to keep track of space left after allocation
    int space_left = 0;

    while (temp_node->nxt != NULL)
    {
        if (strcmp(temp_node->nxt->pr_id, "Unused") == 0 &&temp_node->nxt->free_space >= space_rqstd)
        {
            head_node->free_space = head_node->free_space - space_rqstd;

            strcpy(temp_node->nxt->pr_id, pr_id);
            temp_node->nxt->ending_pointer = temp_node->nxt->starting_pointer + space_rqstd;

            //if space_rqstd is less than the available space.
            space_left = temp_node->nxt->free_space - space_rqstd;
            if (space_left > 0)
            {
                struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node));
                strcpy(new_Node->pr_id, "Unused");
                new_Node->free_space = space_left;
                temp_node->nxt->free_space = space_rqstd;
                new_Node->starting_pointer = temp_node->nxt->ending_pointer + 1;
                new_Node->ending_pointer = new_Node->starting_pointer + space_left;
                if (new_Node->ending_pointer > lastAddress)
                    new_Node->ending_pointer = lastAddress;
					new_Node->nxt = temp_node->nxt->nxt;
					temp_node->nxt->nxt = new_Node;
			}

			return;
		}
		else
			temp_node = temp_node->nxt;
	}

	printf("No space left process %s, of %dkb\n", pr_id, space_rqstd);
}

void RL_memory(char procss_id[3])
{
    printf("releasing memory for process %s\n", procss_id );
    temp_node = head_node;
        while (temp_node->nxt != NULL)
        {
            if (strcmp(temp_node->pr_id, procss_id) == 0){
            free(temp_node);
            temp_node->free_space=0;
    	    printf("Successfully released memory for process %s\n", procss_id);
           return;
            }
            else
		    
            temp_node = temp_node->nxt;

        }
return;
}
int main(int argc, char *argv[])
{

    int init_mem = atoi(argv[1]);
    printf("%d\n", init_mem);
    char usr_input[128];

    printf("allocator>");
    fflush(stdout);

    if (read(0, usr_input, 128) < 0)
       write(2, "Cannot not read input\n", 31);

    head_node = (struct Node *)malloc(sizeof(struct Node));
    blk_of_space = (struct Node *)malloc(sizeof(struct Node));

    strcpy(head_node->pr_id, "Head Node");
    head_node->starting_pointer = -1;
    head_node->ending_pointer = -1;
    head_node->free_space = init_mem;
    head_node->nxt = blk_of_space;

    strcpy(blk_of_space->pr_id, "Unused");
    blk_of_space->starting_pointer = 0;
    blk_of_space->ending_pointer = init_mem;
    blk_of_space->free_space = blk_of_space->ending_pointer - blk_of_space->starting_pointer;
    blk_of_space->nxt = NULL;

    lastAddress = init_mem;

    while (usr_input[0] != 'X')
    {
        if ((sscanf(usr_input, "%s %s", reqst, pr)) < 0)
            write(2, "Cannot not read input\n", 31);


        if (strcmp("RQ", reqst) == 0)
        {

            sscanf(usr_input, "%s %s %d %s", reqst, pr, &space_rqstd, alg_type);
            request_memory(pr, space_rqstd, alg_type);
        }
        else if (strcmp("RL", reqst) == 0)
        {

            sscanf(usr_input, "%s %s", reqst, pr);
            RL_memory(pr);
        }
        else if (strcmp("C", reqst) == 0)
        {
            compact();
            printf("Compaction  process is successful\n");

        }
        else if (strcmp("Status", reqst) == 0)
        {
            stat_report();
        }
        else
        {
            printf(" Unrecognized Command \n");
        }

        stat_report();

        printf("allocator>");
        fflush(stdout);

        if (read(0, usr_input, 128) < 0)
            write(2, "Cannot not read input\n", 31);
    }
    return 0;
}

