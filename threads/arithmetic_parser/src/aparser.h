#ifndef AP_DOT_H //prevent double inclusion of header
#define AP_DOT_H

void ask_for_expression(int);
void inform_user_file_mode(char *);
int process_file(char *);
int sanitize_expression(void);
void parse_expression(void);
void inorder_traversal_evaluate(char *,int);







#endif