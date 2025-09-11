#include <stdio.h>
#include <string.h>

typedef struct
{
    char module [30];
    char status [30];
    int idavion ;
    int capacite ;

}Avions;


typedef struct
{
    char nom [50];
    int nbavion;
    Avions Av[50];
}Aeroport;



void Ajouteravion();
void modifieravion();
void Supprimeravion();
void Afficheravion();
void Rechercheravion();
void Trieravion();
void Affichageaeroport();


int nbavion;
Aeroport Ar[1];
Avions Av[50];
int MenuAvion()
{

    int choix;

    label:
    printf("\n ========================MENU================== \n");
    printf(" 1-Pour ajouter une avoin appuyer sur    1   :\n");

    printf(" 2-Pour modifier une avoin appuyer sur   2   :\n");

    printf(" 3-Pour Supprimer une avoin appuyer sur  3   :\n");

    printf(" 4-Pour Afficher une avoin appuyer sur   4   :\n");

    printf(" 5-Pour Rechercher une avoin appuyer sur 5   :\n");

    printf(" 6-Pour Trier une avoin appuyer sur      6   :\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        Ajouteravion();
        goto label;
    case 2:
        modifieravion();
        goto label;
    case 3:
        Supprimeravion();
        goto label;
    case 4:
        Afficheravion();
        goto label;
    case 5:
        Rechercheravion();
        goto label;
    case 6:
        Trieravion();
        goto label;
    case 0:
        break;
    }

}

void Affichageaeroprt(){
    printf ("SVP saisez le nom de aeroport : \n ");
    scanf("%s",Ar[1].nom);
}
int ID = 1;
int count=1;
void Ajouteravion()
{

    printf("saisir le nombre des avions a ajoutee :\n ");
    scanf("%d", &nbavion);

    int size = nbavion+count;
    
    
    for (int j = count; j <size; j++)
        {
            
            
            printf("Saisir le module d'avion [%d]:",ID);
            scanf(" %[^\n]%*c", Av[j].module);
            printf("Saisir la capacite d'avion [%d]:",ID);
            scanf("%d", &Av[j].capacite);
            printf("anserer le statut [%d]: ",ID);
            scanf(" %[^\n]%*c", Av[j].status);
            printf("\n \n");
            
             
             Av[j].idavion=ID++;
             printf("L id d avion est :%d \n ",Av[j].idavion);
            
        }
        
        count+=nbavion;
        printf("\n \n");
       
        
       
}

// void modifieravion()
// {
//     int idsaisie;
//     printf("Inserer L id d'avion a modifier :\n");
//     scanf("%d",&idsaisie);
//     for (int i = 0; i < count; i++)

//     {
        
//         if (Av[i].idavion==idsaisie)
//         {
//             printf("Saisir le module d'avion [%d]:",i);
//             scanf(" %[^\n]%*c", Av[i].module);
//             printf("Saisir la capacite d'avion [%d]:",i);
//             scanf("%d", &Av[i].capacite);
//             printf("anserer le statut [%d]: ",i);
//             scanf(" %[^\n]%*c", Av[i].status);
//             printf("\n \n");
            
//         }
        
        
        
//     }
    
// }
void Supprimeravion()
{
    int suprrimer;
    printf("Choisser L'id d'avion voulez vous suprrimer :\n");
    scanf("%d",&suprrimer);
    for (int i = 0; i < count; i++)
    {
        if (Av[i].idavion==suprrimer)
        {
            for ( int j = i; j < count; j++)
            {
                Av[i].idavion=Av[i+1].idavion;
                strcopy(Av[i].module,Av[i+1].module);
                strcopy(Av[i].status,Av[i+1].status);
            }
            
            

        }
        
    }
    count--;
    
}
void Afficheravion()
{
    for (int i = 1; i < count; i++)
    {
        printf("Les infos de l'avion [%d]: \n",Av[i].idavion);
        printf("Le module de Lavion  [%d]: %s \n",Av[i].idavion,Av[i].module);
        printf("Le capacite de Lavion  [%d]: %d \n",Av[i].idavion,Av[i].capacite);
        printf("Le statut de Lavion  [%d]: %s \n",Av[i].idavion,Av[i].status);
        printf("\n \n");
       
    }
    printf("\n \n");
   
    

}
void Rechercheravion()
{
    printf("Hello  Rechercheravion");
}
void Trieravion()
{
    printf("Hello  Trieravion");
}
int main(){
    Affichageaeroprt();
    MenuAvion();
} 