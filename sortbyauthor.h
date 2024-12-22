#ifndef SORTBYAUTHOR_H
#define SORTBYAUTHOR_H

struct sortbyauthor
{
    char author_name[100];
    struct sortbyauthor* next;
};
struct sortbyauthor* create_author_node(const char* author_name);
void add_author(struct sortbyauthor** head, const char* author_name);
void view_authors(struct sortbyauthor* head);
void sort_authors(struct sortbyauthor* head);

#endif
