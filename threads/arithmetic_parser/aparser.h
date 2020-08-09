#ifndef AP_DOT_H //prevent double inclusion of header
#define AP_DOT_H

typedef struct s_tree {
    double value;
    int isLeaf;  
    struct S_TREE *left; 
    struct S_TREE *right;  
}S_TREE;

char * ask_for_expression(int);
char * inform_user_file_mode(char *);
int process_file(char *);
void hello(void);
void bye(void);
int process_csv_file(char *);
int sanitize_expression(char *);
void parse_expression(char *);
void inorder_traversal_evaluate(S_TREE *, int);











#endif