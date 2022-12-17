
//Problema care rezolva asezarea a "n" dame(regine) pe tabla de sah
#include <stdio.h>

//variabila in care salvam numarul damelor
int nr_dame;
int dame[8];
int varianta=1;

void afisare_Regine(){
    printf("Varianta "+varianta);
    varianta++;
    for(int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (dame[i] == j) {
                printf("%d ",dame[i]);
            }
            else {
                printf("* ");
            }
        }
    }
    
}

int main() {
    
    printf("Introduceti numarul de dame:");
    scanf("%d",&nr_dame);
    printf("Numarul dame introdus: %d",nr_dame);
    
    return 0;
}