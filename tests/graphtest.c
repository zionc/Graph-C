#include "../graph.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void test()
{
    Graph g = {0};
    graph_init(&g,100);

    Node *node1 = graph_create_node(&g);
    Node *node2 = graph_create_node(&g);

    graph_connect(&g,node1,node2);
    assert(g.nodes_pool_size == 2);
    assert(g.edges_pool_size == 1);

    assert(graph_node_contains(node1,node2));
    assert(!graph_node_contains(node2,node1));

    graph_connect(&g,node2,node1);
    assert(graph_node_contains(node2,node1));

    graph_destroy(&g);
}
void test_create_node()
{
    Graph g = {0};
    graph_init(&g,100);
    Node *node1 = graph_create_node(&g);
    Node *node2 = graph_create_node(&g);
    Node *node3 = graph_create_node(&g);
    assert(g.nodes_pool_size == 3);
    assert(g.edges_pool_size == 0);
    assert(graph_node_pool_contains(&g,node1));
    assert(graph_node_pool_contains(&g,node2));
    assert(graph_node_pool_contains(&g,node3));
    graph_destroy(&g);
    printf("test_create_node: Passed\n");
}


void test_graph_connect()
{
    Graph g = {0};
    graph_init(&g,100);
    Node *node1 = graph_create_node(&g);
    Node *node2 = graph_create_node(&g);
    Node *node3 = graph_create_node(&g);
    assert(node1->adjacent_size == 0);
    assert(node2->adjacent_size == 0);
    assert(node3->adjacent_size == 0);


    graph_connect(&g,node1,node2);
    graph_connect(&g,node1,node3);
    assert(node1->adjacent_size == 2);
    assert(graph_node_contains(node1,node2));
    assert(graph_node_contains(node1,node3));
    assert(!graph_node_contains(node2,node1));
    assert(!graph_node_contains(node3,node1));
    assert(g.edges_pool_size == 2);

    graph_connect(&g,node2,node3);
    assert(node2->adjacent_size == 1);
    assert(node1->adjacent_size == 2);
    assert(node3->adjacent_size == 0);
    assert(graph_node_contains(node2,node3));
    assert(!graph_node_contains(node3,node2));

    graph_connect(&g,node2,node1);
    assert(graph_node_contains(node2,node1));

    assert(g.nodes_pool_size == 3);
    assert(g.edges_pool_size == 4);
    
    graph_destroy(&g);
    printf("test_graph_connect: Passed\n");
    
}

void test_node_equal()
{
    Graph g = {0};
    graph_init(&g,100);

    Node *node1 = graph_create_node(&g);
    Node *node2 = graph_create_node(&g);
    Node *node3 = graph_create_node(&g);
    assert(!graph_node_equals(node1,node2));
    assert(graph_node_equals(node1,node1));
    assert(!graph_node_equals(node3,node2));

    graph_destroy(&g);
    printf("test_node_equal: Passed\n");
}  



int main(void) {
    test_create_node();
    test_graph_connect();
    test_node_equal();
    test();
}