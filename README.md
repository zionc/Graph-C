## Graph Template
Very basic implementation of a Graph using structs. 

This was inspired by an on-going private repo Algo-Visualizer which visualizes algorithms using graphs in pure C.

I figured I'd create this as a base repo and add on to it. New features to be added will be determined by features I'll need from this data structure as my project progresses.

You can find examples of implementation in tests.

## Basic implementation:

```C
Graph g = {0};
graph_init(&g,100); // entry point

Node *node1 = graph_create_node(&g);
Node *node2 = graph_create_node(&g);

graph_connect(&g,node1,node2); 
graph_connect(&g,node2,node1);

graph_destroy(&g);  // always free the heap
```

## Accepts Generic arguments
```C
/* Create struct for additional arguments */
typedef struct Args{
  int id;
  char *name;
} Args;

/* Sample data */
char *names[] = {"Naruto","Sasuke","Gojo","Killua","Gon"};

Graph g = {0};
graph_init(&g,100);

// You can create specific arguments for specific nodes,
// while not touching the Node struct
for(int i = 0; i < 100; i++) {              
    Args arg = {0};
    arg.id = i;
    arg.name = names[i%5];
    graph_create_node_args(&g,(void*)&arg,sizeof(arg));   //needs void pointer to struct and size of struct
}

/* Cast void pointer to struct pointer to access members */
Node *node      = g.nodes_pool[0];
Args *arg       = (Args*)node->args;
char *node_name = arg->name;
char *node_id   = arg->id;

graph_destroy(&g);
```
