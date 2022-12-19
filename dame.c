
//Problema care rezolva asezarea a "n" dame(regine) pe tabla de sah
#include <stdio.h>

//constanta unde definim numarul de dame. Daca se doreste un alt numar, se schimba valoarea
#define NR_DAME 4

int dame[NR_DAME];
int varianta=1;

void afisare_Regine(){
    printf("Varianta %d\n",varianta);
    varianta = varianta + 1;
    for(int i=0; i<NR_DAME; i++) {
        for (int j=0; j<NR_DAME; j++) {
            if (dame[i] == j) {
                printf("%d ",dame[i]);
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
}

void back(int k){
    if(k == NR_DAME) {
        afisare_Regine();
    }
    else {
        for (int i = 0; i < NR_DAME; i++) {
            dame[k] = i;
            if (verificare_Consistenta(k) == 1) {
                back(k+1);
            }
        }
    }
}

int verificare_Consistenta(int nr){
    for(int i=0; i<nr; i++) {
        if(dame[i] == dame[nr])
            return 0;
        if ((dame[i] - dame[nr]) == (nr - i)) 
            return 0;
        if ((dame[nr] - dame[i]) == (nr - i))
            return 0;
    }
    return 1;
}

int main() {
    
   varianta=1;
   back(0);
    
    return 0;
}