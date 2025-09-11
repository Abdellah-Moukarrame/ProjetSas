#include <stdio.h>
#include <string.h>

typedef struct
{
    char module[30];
    char status[30];
    int idavion;
    int capacite;

} Avions;

typedef struct
{
    char nom[50];
    int nbavion;
    Avions Av[50];
} Aeroport;

void Ajouteravion();
void modifieravion();
void Supprimeravion();
void Afficheravion();
void Rechercheravion();
void Trieravion();
void Affichageaeroport();
void Statistique();

int nbavion;
Aeroport Ar[1];
Avions Av[50];
int MenuAvion()
{

    int choix;

label:
    printf("\n========================MENU==================== \n");
    printf(" ||  1-Pour ajouter une avoin appuyer sur     1 ||  \n");

    printf(" ||  2-Pour modifier une avoin appuyer sur    2 ||  \n");

    printf(" ||  3-Pour Supprimer une avoin appuyer sur   3 ||  \n");

    printf(" ||  4-Pour Afficher une avoin appuyer sur    4 ||  \n");

    printf(" ||  5-Pour Rechercher une avoin appuyer sur  5 ||  \n");

    printf(" ||  6-Pour Trier une avoin appuyer sur       6 ||   \n");

    printf(" ||  7-Pour Statistique une avoin appuyer sur 7 ||  \n");

    printf("==================================================");
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
        break;
    case 7:
        Statistique();
        goto label;
        break;
    }
}

void Affichageaeroprt()
{
    printf("SVP saisez le nom de aeroport : \n ");
    scanf("%s", Ar[1].nom);
    printf("Bienvenue au aeroport : %s \n", Ar[1].nom);
}
int ID = 1;
int count = 0;
void Ajouteravion()
{

    printf("saisir le nombre des avions a ajoutee :\n ");
    scanf("%d", &nbavion);

    int size = nbavion + count;

    for (int j = count; j < size; j++)
    {

        printf("Saisir le module d'avion   [%d]:", ID);
        scanf(" %[^\n]%*c", Av[j].module);
        printf("Saisir la capacite d'avion [%d]:", ID);
        scanf("%d", &Av[j].capacite);
        printf("anserer le statut          [%d]: ", ID);
        scanf(" %[^\n]%*c", Av[j].status);
        printf("\n \n");

        Av[j].idavion = ID++;
        printf("L id d avion est :%d \n ", Av[j].idavion);
    }

    count += nbavion;
    printf("\n \n");
}

void modifieravion()
{
    int idsaisie;
    printf("Inserer L id d'avion a modifier :\n");
    scanf("%d", &idsaisie);
    for (int i = 0; i < count; i++)

    {

        if (Av[i].idavion == idsaisie)
        {
            printf("Saisir le module d'avion [%d]:", i);
            scanf(" %[^\n]%*c", Av[i].module);
            printf("Saisir la capacite d'avion [%d]:", i);
            scanf("%d", &Av[i].capacite);
            printf("anserer le statut [%d]: ", i);
            scanf(" %[^\n]%*c", Av[i].status);
            printf("\n \n");
        }
    }
}
void Supprimeravion()
{
    int suprrimer;
    printf("Choisser L'id d'avion voulez vous suprrimer :\n");
    scanf("%d", &suprrimer);
    for (int i = 0; i < count; i++)
    {
        if (Av[i].idavion == suprrimer)
        {
            for (int j = i; j < count-1; j++)
            {
                Av[i].idavion = Av[i + 1].idavion;
            }
        }
    }
    count--;
}
void Afficheravion()
{
    for (int i = 0; i < count; i++)
    {
        printf("Les infos de l'avion  [%d]  : \n", Av[i].idavion);
        printf("Le module de Lavion   [%d]  : %s \n", Av[i].idavion, Av[i].module);
        printf("Le capacite de Lavion [%d]  : %d \n", Av[i].idavion, Av[i].capacite);
        printf("Le statut de Lavion   [%d]  : %s \n", Av[i].idavion, Av[i].status);
        printf("\n \n");
    }
    printf("\n \n");
}
void Rechercheravion()
{
    int choixrecherche;
    printf("Pour rechercher l'avion avec son Id taper 1 :\nPour rechercher l'avion avec son Module taper 2 :\n");
    scanf("%d", &choixrecherche);
    switch (choixrecherche)
    {
    case 1:
        int idarechercher;
        printf("saisir l'id d'avion vous voulez recherchez : \n");
        scanf("%d", &idarechercher);
        for (int i = 0; i < count; i++)
        {
            if (Av[i].idavion == idarechercher)
            {
                printf("Le module de l'avion de ce id   [%d]  : %s \n", i + 1, Av[i].module);
                printf("La capacite de l'avion de ce id [%d]  : %d \n", i+1, Av[i].capacite);
                printf("Le status de l'avion de ce id   [%d]  : %s \n", i+1, Av[i].status);
            }
            else
            {
                printf("Le id que vous avez ajouter est invalid");
            }
        
            
            
        }
        

        break;
    case 2:
        char modulearechercher[50];
        printf("saisir le module d'avion vous voulez recherchez : \n");
        scanf("%s", modulearechercher);
        for (int i = 0; i < count; i++)
        {
            if (strcasecmp(Av[i].module, modulearechercher) == 0)
            {
                printf("Le id de l'avion de ce module       [%d]:%d \n", i+1, Av[i].idavion);
                printf("La capacite de l'avion ce de module [%d]:%d \n", i+1, Av[i].capacite);
                printf("Le status de l'avion de ce module   [%d]:%s \n", i+1, Av[i].status);
            }
            else
            {
                printf("Le module que vous avez ajouter est invalid");
            }
        }

     break;

    default: printf("le choix invalid\n");
        break;
    }
}


void Statistique()
{
    int coixstatistique;
    printf("========================BIENVENUE AU MENU DES STATISTIQUES======================================= \n");
    printf("Pour afficher la nombre total des avions de l'aeroport (%s) entrer 1              :\n", Ar[1].nom);
    printf("Pour afficher la nombre des avions par status de l'aeroport (%s) entrer 2         :\n", Ar[1].nom);
    printf("Pour afficher les avion ayant la plus grande capacité de l'aeroport (%s) entrer 3 :\n", Ar[1].nom);
    printf("Pour afficher les avion ayant la plus petite capacité de l'aeroport (%s) entrer 4 :\n", Ar[1].nom);
    scanf("%d", &coixstatistique);
    switch (coixstatistique)
    {
    case 1:
        printf("nombre totale des avions est: %d", count);
        break;
    case 2:
        int countdispo = 0;
        int countmaintenance = 0;
        int countvol = 0;
        for (int i = 0; i < count; i++)
        {
            if ((strcmp(Av[i].status, "disponible") == 0))
            {
                countdispo++;
            }
            if ((strcmp(Av[i].status, "enmaintenance") == 0))
            {
                countmaintenance++;
            }
            if ((strcmp(Av[i].status, "envol") == 0))
            {
                countvol++;
            }
        }
        printf("les nombres dses avions ont statut disponible     :%d \n", countdispo);
        printf("les nombres dses avions ont statut en maintenance :%d \n", countmaintenance);
        printf("les nombres dses avions ont statut en vol         :%d \n", countvol);

        break;
    case 3:
        int i = 0;
        int max = Av[0].capacite;
        for (i; i < count; i++)
        {
            if (Av[i].capacite > max)
            {
                max = Av[i].capacite;
            }
        }
        printf("l'id de avion ayant la plus grand capacité           :%d \n", Av[i].idavion);
        printf("le module de avion ayant la plus grand capacité      :%s \n", Av[i].module);
        printf("le statut de avion ayant la plus grand capacité      :%s \n", Av[i].status);

        break;
    case 4:
        int j = 0;
        int min = Av[0].capacite;
        for (j; j < count; j++)
        {
            if (Av[j].capacite < min)
            {
                min = Av[j].capacite;
            }
        }
        printf("l'id de avion ayant la plus petite capacité      :%d \n", Av[i].idavion);
        printf("le module de avion ayant la plus petite capacité :%s \n", Av[i].module);
        printf("le statut de avion ayant la plus petite capacité :%s \n", Av[i].status);
        break;

    default:
        break;
    }
}

void Triercapacite()
{
    Avions change;
    for (int i = 0; i < count - 1; i++)
    {

        for (int j = i + 1; j < count; j++)
        {
            if (Av[i].capacite > Av[j].capacite)
            {
                change = Av[i];
                Av[i] = Av[j];
                Av[j] = change;
            }
        }
    }
    Afficheravion();
}
void Triermodule()
{
    Avions change;
    for (int i = 0; i < count - 1; i++)
    {

        for (int j = i + 1; j < count; j++)
        {
            if (Av[i].module > Av[j].module)
            {
                change = Av[i];
                Av[i] = Av[j];
                Av[j] = change;
            }
        }
    }
    Afficheravion();
}

void Trieravion()
{
    int choixtrier;

    printf("pour trier les avions avec capacity entrer 1:\n");
    printf("pour trier les avions avec module entrer 2  :\n");
    scanf("%d \n",&choixtrier);
    switch (choixtrier)
    {
    case 1 :
        Triercapacite();
        break;
    case 2 :
        Triermodule();
        break;
    
    default:
    printf("lechoix que vous avez entrer invalid \n \n");
        break;
    }

}

int main()
{
    Affichageaeroprt();
    MenuAvion();
}