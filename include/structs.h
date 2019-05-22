#include <stdio.h>
#include <stdlib.h> 
struct UserInfo{
    char s[22];
    int gameCount;
    int totScore;
    int bestScore;
    int ID;
    int rank;
};

struct Maping{
    UserInfo findByID(){

    }
    UserInfo findByName(char *s){

    }
};

struct List{
    int ID,score;
    struct List* next;
};

struct RankList{
    int totNum;
    struct List* head;
    void insert(int ID,int score){
        struct List *tmp = (struct List*)malloc(sizeof(struct List));
        tmp->ID = ID;tmp->score = score;tmp->next = NULL;
        if(head == NULL) head = tmp;
        else{
            if(score > head->score){
                tmp->next = head;
                head = tmp;
            }else{
                struct List *i = head->next;
                struct List *j = head;
                while(1){
                    if(i == NULL || score > i->score){
                        j->next = tmp;
                        tmp->next = i;
                        break;
                    }
                }
            }
        }
    }
    void erase(int ID){
        if(head == NULL) return ;
        if(head->ID == ID){
            struct List * it = head;
            head = head->next;
            delete(it);
        }
        struct List * i = head->next;
        struct List * j = head;
        for(;i != NULL;i = i->next,j = j->next){
            if(i->ID == ID){
                j->next = i->next;
                break;
            }
        }
    }
};
