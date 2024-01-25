### Keep expectations low
Very basic implementation of a Graph using structs. 

This was inspired by an on-going private repo Algo-Visualizer which visualizes algorithms using graphs in pure C.

I figured I'd create this as a base repo and add on to it. New features to be added will be determined by features I'll need from this data structure as my project progresses.

You can find examples of implementation in tests.

# Basic implementation:

0 initialize Graph struct
```C
Graph g = {0};
```
initialize Graph with a maximum of 100 nodes
```C
graph_init(&g,100);
```
create a node
```C
Node *node1 = graph_create_node(&g);
```
create another node
```C
Node *node2 = graph_create_node(&g);
```
connect node 1 to node 2
```C
graph_connect(&g,node1,node2);
```
connect node 2 to node 1
```C
graph_connect(&g,node2,node1);
```
Always free the heap whenever Graph is not needed
```C
graph_destroy(&g);
```
