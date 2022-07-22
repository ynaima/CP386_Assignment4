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

            //if the space_rqstd is smaller then the space found.
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
