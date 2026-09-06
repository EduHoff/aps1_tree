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

    print_organogram(diretor);
    
    nary_tree_free(diretor);
    return 0;
}
