
//Problema care rezolva asezarea a "n" dame(regine) pe tabla de sah
#include <stdio.h>

//constanta unde definim numarul de dame. Daca se doreste un alt numar, se schimba valoarea aici
#define NR_DAME 8

//vector unde salvam damele
int dame[NR_DAME];
//variabila unde contorizam numarul de variante gasite
int varianta=1;

/*in acesta functie se afiseaza asezarea damelor pe tabla de saj
se va marga in "matricea de sah" cate o dama cu numarul aferent ei si restul pozitiilor cu asterix*/
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

/*Functie backtraking unde se cauta toate solutiile de asezarea a damelor
Se genereaza toate permutarile posibile folosind backtraking*/
void back(int k){
    //conditia de oprire a backtrakingului este cand am generat solutii pentru toate damele
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

//Functie in care verificam sa nu avem conflict intre dame
//Se stie ca 2 dame nu au voie sa fie pe aceeasi linie, coloana sau diagonala
int verificare_Consistenta(int nr){
    for(int i=0; i<nr; i++) {
        if(dame[i] == dame[nr]) //verificam daca avem regina pe aceeasi coloana
            return 0;
        if ((dame[i] - dame[nr]) == (nr - i)) // verificam daca avem regina pe aceeasi diagonala principala
            return 0;
        if ((dame[nr] - dame[i]) == (nr - i)) // verificam daca avem regina pe aceeasi diagonala secundara
            return 0;
    }
    return 1;
}

/*Functia principala de unde incepe executia programului.
Se apeleaza functia de backtrking (incepem de la pozitia 0) pentru generarea tuturor solutiilor*/
int main() {
    
    back(0);
    
    printf("Pentru a aseza %d dame pe tabla de sah exista %d variante.",NR_DAME,varianta-1);
    
    return 0;
}