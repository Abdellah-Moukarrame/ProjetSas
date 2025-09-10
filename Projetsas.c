#include <stdio.h>
#include <string.h>

typedef struct 
{
    char module [30];
    char status [30];
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

int nbavion;
Avions Av[50];
int main()
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

void Ajouteravion()
{
    
    printf("saisir le nombre des avions a ajoutee :\n ");
    scanf("%d", &nbavion);
    
    
    for (int j = 0; j < nbavion; j++)
        {
            int statut;
            printf("Saisir le module d'avion %d:" ,j);
            getchar();
            fgets(Av[j].module,sizeof(Av[j].module),stdin);
            printf("Saisir la capacite d'avion %d:",j);
            scanf("%d %[^\n]", &Av[j].capacite);
            getchar();
            printf("taper 1 pour disponible \n taper 2 pour En maintenance \n taper 3 pour En vol");
            scanf("%d %[^\n]", &statut);
            getchar();
            switch (statut)
            {
            case 1:
                statut == "disponible";
                break;
            case 2:
                statut == "en maintenance";
                break;
            case 3:
                statut == "en vol";
                break;

            default:
                break;
            }
        }
}

void modifieravion()
{
    printf("Hello  modifieravion");
}
void Supprimeravion()
{
    printf("Hello  Supprimeravion");
}
void Afficheravion()
{
    for (int i = 0; i < nbavion; i++)
    {
        printf("Le module de Lavion %s :\n",i+1,Av[i].module);
        printf("Le capacite de Lavion %d :\n",i+1,Av[i].capacite);
        printf("Le statut de Lavion %s :\n",i+1,Av[i].status);
    }
    
}
void Rechercheravion()
{
    printf("Hello  Rechercheravion");
}
void Trieravion()
{
    printf("Hello  Trieravion");
}