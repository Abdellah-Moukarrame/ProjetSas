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

    printf(" =================================================  \n");
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
    scanf(" %[^\n]%*c", Ar[1].nom);
    printf("Bienvenue au aeroport : %s \n", Ar[1].nom);
}
int ID = 1;
int count = 0;
void Ajouteravion()
{

    printf("saisir le nombre des avions a ajoutee :\n ");
    scanf("%d", &nbavion);

    int size = nbavion + count;
    int choixstatus;
    for (int j = count; j < size; j++)
    {

        printf("Saisir le module d'avion   [%d]:", ID);
        scanf(" %[^\n]%*c", Av[j].module);
        printf("Saisir la capacite d'avion [%d]:", ID);
        scanf("%d", &Av[j].capacite);
        printf("choisisser le statut :\n pour envol entrer 1\n pour disponible entrer 2\n pour en maintenance entrer 3\n");
        scanf("%d", &choixstatus);

        switch (choixstatus)
        {
        case 1:
            strcpy(Av[j].status, "en vol");
            break;
        case 2:
            strcpy(Av[j].status, "disponible");
            break;
        case 3:
            strcpy(Av[j].status, "en maintenance");
            break;
        default:
            printf("choix est invalid \n");
            strcpy(Av[j].status, "disponible");
            break;
        }

        printf("statut que vous avez choisi est : %s \n", Av[j].status);

        printf("\n \n");

        Av[j].idavion = ID++;
        printf("L id d avion est :%d \n \n \n ", Av[j].idavion);
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
            printf("Saisir le module d'avion :");
            scanf(" %[^\n]%*c", Av[i].module);
            printf("Saisir la capacite d'avion :");
            scanf("%d", &Av[i].capacite);
            printf("anserer le statut : ");
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
            for (int j = i; j < count - 1; j++)
            {
                Av[i] = Av[i + 1];
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
        int trouve = 0;
        printf("saisir l'id d'avion vous voulez recherchez : \n");
        scanf("%d", &idarechercher);
        for (int i = 0; i < count; i++)
        {
            if (Av[i].idavion == idarechercher)
            {
                printf("Le module de l'avion de ce id   [%d]  : %s \n", i + 1, Av[i].module);
                printf("La capacite de l'avion de ce id [%d]  : %d \n", i + 1, Av[i].capacite);
                printf("Le status de l'avion de ce id   [%d]  : %s \n", i + 1, Av[i].status);
            }
            trouve = 1;
        }
        if (trouve == 0)
        {
            printf("le id que vous avez ajouter est invalid \n");
        }

        break;
    case 2:
        char modulearechercher[50];
        printf("saisir le module d'avion vous voulez recherchez : \n");
        scanf("%s", modulearechercher);
        int trouver = 0;
        for (int i = 0; i < count; i++)
        {
            if (strcasecmp(Av[i].module, modulearechercher) == 0)
            {
                printf("Le id de l'avion de ce module       [%d]:%d \n", i + 1, Av[i].idavion);
                printf("La capacite de l'avion ce de module [%d]:%d \n", i + 1, Av[i].capacite);
                printf("Le status de l'avion de ce module   [%d]:%s \n", i + 1, Av[i].status);
            }
            trouver = 1;
        }
        if (trouver == 0)
        {
            printf("le module que vous avez ajouter est invalid \n");
        }

        break;

    default:
        printf("le choix invalid\n");
        break;
    }
}

void Statistique()
{
    int coixstatistique;
    printf("========================BIENVENUE AU MENU DES STATISTIQUES========================= \n");
    printf("Pour afficher la nombre total des avions de l'aeroport entrer               1:\n");
    printf("Pour afficher la nombre des avions par status de l'aeroport entrer          2:\n");
    printf("Pour afficher les avion ayant la plus grande capacité de l'aeroport entrer  3:\n");
    printf("Pour afficher les avion ayant la plus petite capacité de l'aeroport entrer  4:\n");
    printf("Pour afficher le qoficient des avion disponible                             5:\n");
    printf("Pour afficher la capacite totale des avion disponible                       6:\n");

    scanf("%d", &coixstatistique);
    int countdispo=0 ;
    switch (coixstatistique)
    {
    case 1:
        printf("nombre totale des avions est: %d", count);
        break;
    case 2:
         countdispo;
        int countmaintenance = 0;
        int countvol = 0;
        for (int i = 0; i < count; i++)
        {
            if ((strcmp(Av[i].status, "disponible") == 0))
            {
                countdispo++;
            }
            if ((strcmp(Av[i].status, "en maintenance") == 0))
            {
                countmaintenance++;
            }
            if ((strcmp(Av[i].status, "en vol") == 0))
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
        int index;
        int max = Av[0].capacite;
        for (i; i < count; i++)
        {
            if (Av[i].capacite > max)
            {
                max = Av[i].capacite;
                index=i;
            }
        }
        printf("l'id de avion ayant la plus grand capacité           :%d \n", Av[index].idavion);
        printf("le module de avion ayant la plus grand capacité      :%s \n", Av[index].module);
        printf("le statut de avion ayant la plus grand capacité      :%s \n", Av[index].status);

        break;
    case 4:
        int j = 0;
        int indexx;
        int min = Av[0].capacite;
        for (j; j < count; j++)
        {
            if (Av[j].capacite < min)
            {
                min = Av[j].capacite;
                indexx=j;
            }
        }
        printf("l'id de avion ayant la plus petite capacité      :%d \n", Av[indexx].idavion);
        printf("le module de avion ayant la plus petite capacité :%s \n", Av[indexx].module);
        printf("le statut de avion ayant la plus petite capacité :%s \n", Av[indexx].status);
        break;
    case 5:
        float qoficient = ( countdispo/count)*100;

        printf("l'qoficient des avions disponible :%.2f %% \n",qoficient);
        break;
    case 6:
        int sommecapacity=0;
        for (int i = 0; i < count; i++)
        {
            sommecapacity+=Av[i].capacite;
        }
        printf("la somme des capicity des avions est :%d",sommecapacity);
        

        
        

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
    for (int X = 0; X < count; X++)
    {
        printf("Les infos de l'avion  [%d]  : \n", Av[X].idavion);
        printf("Le module de Lavion   [%d]  : %s \n", Av[X].idavion, Av[X].module);
        printf("Le capacite de Lavion [%d]  : %d \n", Av[X].idavion, Av[X].capacite);
        printf("Le statut de Lavion   [%d]  : %s \n", Av[X].idavion, Av[X].status);
        printf("\n \n");
    }
    printf("\n \n");
}
void Triermodule()
{
    Avions change;
    for (int i = 0; i < count - 1; i++)
    {

        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(Av[i].module, Av[j].module) > 0)

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
    scanf("%d", &choixtrier);
    switch (choixtrier)
    {
    case 1:
        Triercapacite();
        break;
    case 2:
        Triermodule();
        break;

    default:
        printf("lechoix que vous avez entrer invalid \n \n");
        return;
    }
}

int main()
{
    Affichageaeroprt();
    MenuAvion();
}