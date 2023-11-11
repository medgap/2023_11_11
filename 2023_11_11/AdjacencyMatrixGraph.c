#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct Graph{
    char* vexs;
    int** arcs;
    int verNum;
    int arcNum;
}Graph;

Graph* initGraph(int verNum){
    Graph* G = (Graph*)malloc(sizeof(Graph));
    G->vexs = (char*)malloc(sizeof(char) * verNum);
    G->verNum = verNum;
    G->arcs = (int**)malloc(sizeof(int*) * verNum);
    for(int i = 0; i < verNum; i++){
        G->arcs[i] = (int*)malloc(sizeof(int) * verNum);
    }
    G->arcNum = 0;
}

void createGraph(Graph* G, char* vexs, int* arcs){
    for(int i = 0; i < G->verNum; i++){
        G->vexs[i] = vexs[i];
        for(int j = 0; j < G->verNum; j++){
            G->arcs[i][j] = *(arcs + i * G->verNum + j);
            if(G->arcs[i][j] != 0)
                G->arcNum++;
        }
    }
    G->arcNum /= 2;
}

int main(int argc,char* argv[]){
    Graph* g = initGraph(MAXSIZE);
    int arr[MAXSIZE][MAXSIZE] = {
            0,1,1,1,0,
            1,0,1,1,1,
            1,1,0,0,0,
            1,1,0,0,1,
            0,1,0,1,0
    };
    createGraph(g,"ABCDE",(int*)arr);
    return 0;
}