#include "person.h"

Person new_person(char* n, int a){
    Person p;
    p.name = malloc(sizeof(char*)+1);
    p.name = strcpy(n,)
    //ou fazer strdup
    p.age = a;
    return p;
}

Person clone_person(Person* p){
    char* cn = 
    Person cl = new_person();
    return cl;
}