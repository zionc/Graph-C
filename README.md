Very basic implementation of a Graph using structs. 

This was inspired by an on-going private repo Algo-Visualizer which visualizes algorithms using graphs in pure C.

I figured I'd create this as a base repo and add on to it. New features to be added will be determined by features I'll need from this data structure as my project progresses.

```C
Graph g = {0};
    graph_init(&g,100);

    Node *node1 = graph_create_node(&g);
    Node *node2 = graph_create_node(&g);

    graph_connect(&g,node1,node2);
    graph_connect(&g,node2,node1);

graph_destroy(&g);
```
