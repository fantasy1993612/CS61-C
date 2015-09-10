#include <stdio.h>

typedef struct node {
	int value;
	struct node *next;
} node;
/*
Start with two pointers at the head of the list. We'll call the first one tortoise and the second one hare.
Advance hare by two nodes. If this is not possible because of a null pointer, we have found the end of the list, and therefore the list is acyclic.
Advance tortoise by one node. (A null pointer check is unnecessary. Why?)
If tortoise and hare point to the same node, the list is cyclic. Otherwise, go back to step 2.
*/
int ll_has_cycle(node *head) {
	/* your code here */
	if(head == NULL){
		return 0;
	}
	
	node* cur = head;
	node* prev = head;
	while(cur->next != NULL){
		cur = cur->next;	
		prev = head;
		if(prev == cur){
			return 1;
		}
		while(prev != cur){
			if(cur->next == prev){
				return 1;
			}
			prev = prev->next;
		}
		
	}

	return 0;
}

void test_ll_has_cycle(void) {
	int i;
	node nodes[25]; //enough to run our tests
	for(i=0; i < sizeof(nodes)/sizeof(node); i++) {
		nodes[i].next = 0;
		nodes[i].value = 0;
	}
	
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = &nodes[3];
	printf("Checking first list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[0])?"a":"no");
  
	nodes[4].next = &nodes[5];
	nodes[5].next = &nodes[6];
	nodes[6].next = &nodes[7];
	nodes[7].next = &nodes[8];
	nodes[8].next = &nodes[9];
	nodes[9].next = &nodes[10];
	nodes[10].next = &nodes[4];
	printf("Checking second list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[4])?"a":"no");
  
	nodes[11].next = &nodes[12];
	nodes[12].next = &nodes[13];
	nodes[13].next = &nodes[14];
	nodes[14].next = &nodes[15];
	nodes[15].next = &nodes[16];
	nodes[16].next = &nodes[17];
	nodes[17].next = &nodes[14];
	printf("Checking third list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[11])?"a":"no");
  
	nodes[18].next = &nodes[18];
	printf("Checking fourth list for cycles. There should be a cycle, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[18])?"a":"no");
  
	nodes[19].next = &nodes[20];
	nodes[20].next = &nodes[21];
	nodes[21].next = &nodes[22];
	nodes[22].next = &nodes[23];
	printf("Checking fifth list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(&nodes[19])?"a":"no");
  
	printf("Checking length-zero list for cycles. There should be none, ll_has_cycle says it has %s cycle\n", ll_has_cycle(NULL)?"a":"no");
	
}

int main(void) {
  test_ll_has_cycle();
  return 0;
}
