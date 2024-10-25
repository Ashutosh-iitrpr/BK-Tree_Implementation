#ifndef HEADER_H
#define HEADER_H

int min(int a, int b, int c);
int lev_dist(char* a, char* b);

#define NEG_INF -100000
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int abs(int a);
void evaluate(int** f, char* a, char* b, int k, int p);
int edit_dist(int** f, char* a, char* b);
int UK_lev_dist(char* a, char* b);

char **array_maker(char *filename);

#endif
