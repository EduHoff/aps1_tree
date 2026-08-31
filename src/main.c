#include "ds.h"
#include "utils.h"

int main(void) {
    clear_screen();

    NaryTreeNode* diretor = create_node("Diretor Geral", 1);
    NaryTreeNode* ger_ti = create_node("Gerente de TI", 1);
    NaryTreeNode* ger_vendas = create_node("Gerente de Vendas", 1);
    NaryTreeNode* dev = create_node("Desenvolvedor", 1);
    NaryTreeNode* analista = create_node("Analista de Vendas", 1);

    diretor->first_child = ger_ti;
    ger_ti->next_sibling = ger_vendas;
    ger_ti->first_child = dev;
    ger_vendas->first_child = analista;

    print_organogram(diretor);
    
    free_tree(diretor);
    return 0;
}
