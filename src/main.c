#include "ds.h"
#include "utils.h"

int main(void) {
    clear_screen();

    NaryTreeNode* diretor = nary_tree_create_node("Diretor Geral", 1);
    NaryTreeNode* ger_ti = nary_tree_create_node("Gerente de TI", 1);
    NaryTreeNode* ger_vendas = nary_tree_create_node("Gerente de Vendas", 1);
    NaryTreeNode* dev = nary_tree_create_node("Desenvolvedor", 1);
    NaryTreeNode* analista = nary_tree_create_node("Analista de Vendas", 1);

    diretor->first_child = ger_ti;
    ger_ti->next_sibling = ger_vendas;
    ger_ti->first_child = dev;
    ger_vendas->first_child = analista;

    nary_tree_print_organogram(diretor);
    nary_tree_free(diretor);

    BinaryTreeNode* root = binary_tree_create_node("A", 1);
    BinaryTreeNode* node_b = binary_tree_create_node("B", 1);
    BinaryTreeNode* node_c = binary_tree_create_node("C", 1);
    BinaryTreeNode* node_d = binary_tree_create_node("D", 1);
    BinaryTreeNode* node_e = binary_tree_create_node("E", 1);

    root->left = node_b;
    root->right = node_c;

    node_b->left = node_d;
    node_b->right = node_e;

    binary_tree_print_organogram(root);
    binary_tree_free(root);

    return 0;
}

/*
    APS 1: Os alunos deverão construir um software que seja capaz de realizar e representar as operações (inserir, remover,
    percorrer{sinalizando qual é o nó atual}) em uma estrutura de dados não linear (à escolha dos alunos). Esta representação deverá ser visual
    para que o usuário do sistema consiga perceber a movimentação que está acontecendo na árvore (passo a passo).
    APS 2: Os alunos deverão utilizar a APS1 para construir uma nova opção em um menu onde será necessário realizar a construção e
    visualização de um grafo a partir de uma matriz de adjacência. Além disto nesta representação deve ser capaz de ser representado o peso
    de cada aresta e calcular o caminho mínimo.

    Desafio 1: Usando a APS1 os alunos deverão gerar árvores de diversos tamanhos e realizar comparativos entre as formas de busca dentro
    da estrutura para levantar uma relação de desempenho de cada forma de busca.
    Desafio 2: Simular a função de um GPS para calcular a melhor rota baseado em tempo ou baseado em distância ou baseado em menos
    pedágios ou um mix personalizado disso.
 */
