#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef _WIN32
    #include<direct.h>
    #define MKDIR(PATH) _mkdir(PATH)
    #define SEP '\\'
#else
    #include<sys/stat.h>
    #define MKDIR(PATH) mkdir(PATH,0777)
    #define SEP '/'
#endif
typedef struct {
    char nom[20];
    float moy;
    float moyC;
    int Coef;
    int nbreno;
    float *n;
    float somnot;
}subject;
typedef struct {
    char nom[20];
    char pre[20];
    char nma[20];
    char nmi[20];
    long int ID;
    subject *sub;
    int nbresub;
    float sommoyC;
    float moyma;
    float moymi;
    float moyg;
    int nbreva;
    char *dec;
}student;
 typedef struct {
    char nom_cl[20];
    student *stu;
    int nbredetu;
    float moygma;
    float moygmi;
    char negma[20];
    char negmi[20];
    char pegma[20];
    char pegmi[20];
    int nbra;
    int nbre;
}classe;
int main(){
    int I,Cl,J,K,F,f,Ff,con,Co,L,M,YEAR,Fn;
    char NE[25];
    printf("ENTER SCHOOL NAME(NO SPACE USE\"_\"TO SEPARATE):");
    scanf("%24s",NE);
    while(getchar() != '\n');
    do{
        printf("\nENTER THE YEAR:");
        if(scanf("%d",&YEAR) != 1){
            printf("\nINVALID INPUT,TRY AGAIN.");
            while(getchar() != '\n');
            con=0;
        }
        printf("ENTER 1 TO CONFIRM THE YEAR AND ANOTHER KEY TO RESTART: ");
            if(scanf("%d",&con)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
                con=0;
            }
    }while(con!=1);
    do{
        printf("\nENTER THE NUMBER OF CLASS: ");
        if(scanf("%d",&Cl)!=1){
            printf("INVALID INPUT,TRY AGAIN.");
            while(getchar() != '\n');
            Cl=0;
        }
        printf("\nENTER 1 TO CONFIRM THE NUMBER AND ANOTHER KEY TO RESTART: ");
        if(scanf(" %d",&con)!=1){
            printf("\nINVALID INPUT,TRY AGAIN.");
            while(getchar() != '\n');
            con=0;
        }
    }while(Cl<=0 || con!=1);
    classe *clas;
    clas=(classe*)calloc(Cl,sizeof(classe));
    if(clas==NULL){
        printf("\nREQUIRED SPACE NOT AVAILABLE.");
        return 1;
    }
    for(K=0;K<Cl;K++){
        clas[K].nbra=0;
        clas[K].nbre=0;
        do{
            printf("\nENTER THE CLASS %d NAME (NO SPACE USE\"_\"TO SEPARATE):",K+1);
            scanf("%19s",clas[K].nom_cl);
            while(getchar() != '\n');
            printf("\nENTER 1 TO CONFIRM THE NAME AND ANOTHER KEY TO RESTART: ");
            if(scanf(" %d",&con)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
                con=0;
            }
        }while(con!=1);
        do{
            printf("\nENTER THE NUMBER OF STUDENTS IN %s :",clas[K].nom_cl);
            if(scanf("%d",&clas[K].nbredetu) != 1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
                con=0;
            }
            printf("ENTER 1 TO CONFIRM THE NUMBER AND ANOTHER KEY TO RESTART: ");
            if(scanf("%d",&con)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
                con=0;
            }
        }while(clas[K].nbredetu<=0 || con!=1);
        clas[K].stu=(student*)calloc(clas[K].nbredetu,sizeof(student));
        if(clas[K].stu==NULL){
            printf("\nREQUIRED SPACE NOT AVAILABLE.");
            free(clas);
            return 1;
        }
        for(I=0;I<clas[K].nbredetu;I++){
            do{
                printf("\nENTER THE FIRST NAME OF STUDENT %d IN %s(NO SPACE USE\"_\"TO SEPARATE):",I+1,clas[K].nom_cl);
                scanf("%19s",clas[K].stu[I].pre);
                while(getchar() != '\n');
                printf("\nENTER THE LAST NAME OF STUDENT %d IN %s(NO SPACE USE\"_\"TO SEPARATE):",I+1,clas[K].nom_cl);
                scanf("%19s",clas[K].stu[I].nom);
                while(getchar() != '\n');
                printf("\nENTER 1 TO CONFIRM THE NAME AND ANOTHER KEY TO RESTART: ");
                if(scanf("%d",&con)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while(getchar() != '\n');
                    con=0;
                }
            }while(con!=1);
            do{
                printf("\nENTER %s %s ID (%s) :",clas[K].stu[I].pre,clas[K].stu[I].nom,clas[K].nom_cl);
                if(scanf("%ld",&clas[K].stu[I].ID)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while(getchar() != '\n');
                    con=0;
                }
                printf("\nENTER 1 TO CONFIRM THE ID AND ANOTHER KEY TO RESTART: ");
                if(scanf("%d",&con)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while(getchar() != '\n');
                    con=0;
                }
            }while(con!=1);
            do{
                printf("\nENTER THE NUMBER OF SUBJECTS IN %s FOR %s %s:",clas[K].nom_cl,clas[K].stu[I].pre,clas[K].stu[I].nom);
                if(scanf("%d",&clas[K].stu[I].nbresub)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while(getchar() != '\n');
                    con=0;
                }
                printf("\nENTER 1 TO CONFIRM THE NUMBER AND ANOTHER KEY TO RESTART: ");
                if(scanf("%d",&con)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while(getchar() != '\n');
                    con=0;
                }
            }while(clas[K].stu[I].nbresub<=0 || con!=1);
            clas[K].stu[I].sub=(subject*)calloc(clas[K].stu[I].nbresub,sizeof(subject));
            if(clas[K].stu[I].sub==NULL){
                printf("\nREQUIRED SPACE NOT AVAILABLE.");
                for(F=0;F<Cl;F++)
                    free(clas[F].stu);
                free(clas);
                return 1;
            }
            Co=0;
            clas[K].stu[I].sommoyC=0;
            clas[K].stu[I].nbreva=0;
            for(J=0;J<clas[K].stu[I].nbresub;J++){
                do{
                    printf("\nENTER THE NAME OF SUBJECT %d OF %s %s (%s)(NO SPACE USE\"_\"TO SEPARATE): ",J+1,clas[K].stu[I].pre,clas[K].stu[I].nom,clas[K].nom_cl);
                    scanf("%19s",clas[K].stu[I].sub[J].nom);
                        while(getchar() != '\n');
                        printf("ENTER 1 TO CONFIRM THE NAME AND ANOTHER KEY TO RESTART:  ");
                        if(scanf(" %d",&con)!=1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                            while(getchar() != '\n');
                            con=0;
                        }
                }while(con!=1);
                do{
                    printf("\nENTER THE COEF OF %s IN %s : ",clas[K].stu[I].sub[J].nom,clas[K].nom_cl);
                    if( scanf(" %d",&clas[K].stu[I].sub[J].Coef)!=1){
                        printf("\nINVALID INPUT,TRY AGAIN.");
                        while(getchar() != '\n');
                        con=0;
                    }
                    printf("ENTER 1 TO CONFIRM THE COEF AND ANOTHER KEY TO RESTART: ");
                    if(scanf(" %d",&con)!=1){
                        printf("\nINVALID INPUT,TRY AGAIN.");
                        while(getchar() != '\n');
                        con=0;
                    }
                }while(clas[K].stu[I].sub[J].Coef<=0 || con!=1);
                Co+=clas[K].stu[I].sub[J].Coef;
                do{
                    printf("\nENTER THE NUMBER OF NOTE OF %s IN %s : ",clas[K].stu[I].sub[J].nom,clas[K].nom_cl);
                    if(scanf("%d",&clas[K].stu[I].sub[J].nbreno)!=1){
                        printf("\nINVALID INPUT,TRY AGAIN.");
                        while(getchar() != '\n');
                        con=0;
                    }
                    printf("\nENTER 1 TO CONFIRM THE NUMBER AND ANOTHER KEY TO RESTART: ");
                    if(scanf("%d",&con)!=1){
                        printf("\nINVALID INPUT,TRY AGAIN.");
                        while(getchar() != '\n');
                        con=0;
                    }
                }while(clas[K].stu[I].sub[J].nbreno<=0 || con!=1);
                clas[K].stu[I].sub[J].n=(float*)calloc(clas[K].stu[I].sub[J].nbreno,sizeof(float));
                if(clas[K].stu[I].sub[J].n==NULL){
                    printf("\nREQUIRED SPACE NOT AVAILABLE.");
                    for(F=0;F<Cl;F++){
                        for(f=0;f<clas[F].nbredetu;f++)
                            free(clas[F].stu[f].sub);
                        free(clas[F].stu);
                    }
                    free(clas);
                    return 1;
                }
                clas[K].stu[I].sub[J].somnot=0;
                for(L=0;L<clas[K].stu[I].sub[J].nbreno;L++){
                    do{
                        printf("\nENTER THE NOTE %d IN %s OF %s %s : ",L+1,clas[K].stu[I].sub[J].nom,clas[K].stu[I].pre,clas[K].stu[I].nom);
                        if(scanf("%f",&clas[K].stu[I].sub[J].n[L])!=1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                            while(getchar() != '\n');
                            con=0;
                        }
                        printf("\nENTER 1 TO CONFIRM THE NOTE AND ANOTHER KEY TO RESTART: ");
                        if(scanf("%d",&con)!=1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                            while(getchar() != '\n');
                            con=0;
                        }
                    }while(clas[K].stu[I].sub[J].n[L]<0 || clas[K].stu[I].sub[J].n[L]>20 || con!=1);
                    clas[K].stu[I].sub[J].somnot+=clas[K].stu[I].sub[J].n[L];
                }
                clas[K].stu[I].sub[J].moy=(clas[K].stu[I].sub[J].somnot/clas[K].stu[I].sub[J].nbreno);
                if(clas[K].stu[I].sub[J].moy>=12)
                    clas[K].stu[I].nbreva+=1;
                clas[K].stu[I].sub[J].moyC=(clas[K].stu[I].sub[J].somnot/clas[K].stu[I].sub[J].nbreno)*clas[K].stu[I].sub[J].Coef;
                clas[K].stu[I].sommoyC+=clas[K].stu[I].sub[J].moyC;
            }
            clas[K].stu[I].moyg=(clas[K].stu[I].sommoyC/Co);
            if(clas[K].stu[I].moyg>=12){
                clas[K].stu[I].dec="PASS";
                clas[K].nbra+=1;
            }
            else{
                clas[K].stu[I].dec="FAIL";
                clas[K].nbre+=1;
            }
            clas[K].stu[I].moyma=clas[K].stu[I].sub[0].moy;
            clas[K].stu[I].moymi=clas[K].stu[I].sub[0].moy;
            strcpy(clas[K].stu[I].nma,clas[K].stu[I].sub[0].nom);
            strcpy(clas[K].stu[I].nmi,clas[K].stu[I].sub[0].nom);
            for(M=0;M<clas[K].stu[I].nbresub;M++){
                if(clas[K].stu[I].sub[M].moy<clas[K].stu[I].moymi){
                    clas[K].stu[I].moymi=clas[K].stu[I].sub[M].moy;
                    strcpy(clas[K].stu[I].nmi,clas[K].stu[I].sub[M].nom);
                }
                if(clas[K].stu[I].sub[M].moy>clas[K].stu[I].moyma){
                    clas[K].stu[I].moyma=clas[K].stu[I].sub[M].moy;
                    strcpy(clas[K].stu[I].nma,clas[K].stu[I].sub[M].nom);
                }
            }
        }
        clas[K].moygma=clas[K].stu[0].moyg;
        clas[K].moygmi=clas[K].stu[0].moyg;
        strcpy(clas[K].negma,clas[K].stu[0].nom);
        strcpy(clas[K].negmi,clas[K].stu[0].nom);
        strcpy(clas[K].pegma,clas[K].stu[0].pre);
        strcpy(clas[K].pegmi,clas[K].stu[0].pre);
        for(M=0;M<clas[K].nbredetu;M++){
            if(clas[K].stu[M].moyg<clas[K].moygmi){
                clas[K].moygmi=clas[K].stu[M].moyg;
                strcpy(clas[K].negmi,clas[K].stu[M].nom);
                strcpy(clas[K].pegmi,clas[K].stu[M].pre);
            }
            if(clas[K].stu[M].moyg>clas[K].moygma){
                clas[K].moygma=clas[K].stu[M].moyg;
                strcpy(clas[K].negma,clas[K].stu[M].nom);
                strcpy(clas[K].pegma,clas[K].stu[M].pre);
            }
        }
    }
    char *ney;
    ney=calloc(45,sizeof(char));
    if(ney==NULL){
        printf("\nREQUIRED SPACE NOT AVAILABLE.");
        for(F=0;F<Cl;F++){
            for(f=0;f<clas[F].nbredetu;f++){
                for(Ff=0;Ff<clas[F].stu[f].nbresub;Ff++)
                    free(clas[F].stu[f].sub[Ff].n);
                free(clas[F].stu[f].sub);
            }
            free(clas[F].stu);
        }
        free(clas);
        return 1;
    }
    do{
        con=1;
        printf("ENTER 1 TO INPUT THE FOLDER NAME AND OTHER TO GENERATE A NAME TO FOLDER:");
        if(scanf("%d",&Fn)!=1){
            printf("INVALID INPUT,TRY AGAIN.");
            while(getchar() != '\n');
            con=0;
        }
    }while(con!=1);
    if(Fn==1){
        do{
            printf("\nENTER THE FOLDER NAME (NO SPACE USE\"_\"TO SEPARATE YOU CAN USE A PATH(PARENT'S FOLDER%cFOLDER NAME)IF PARENT'S FOLDER EXIST):",SEP);
            scanf("%44s",ney);
            printf("\nENTER 1 TO CONFIRM THE NAME AND ANOTHER KEY TO RESTART: ");
            if(scanf(" %d",&con)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
                con=0;
            }
        }while(con!=1);
    }
    else{
        sprintf(ney,"%s_%d",NE,YEAR);
    }
    MKDIR(ney);
    char *NEY;
    NEY=calloc(80,sizeof(char));
    sprintf(NEY,"%s%c%s_%d.rtf",ney,SEP,NE,YEAR);
    FILE *fl;
    if((fl=fopen(NEY,"wb"))==NULL){
        printf("FILE CREATING ERROR");
        for(F=0;F<Cl;F++){
            for(f=0;f<clas[F].nbredetu;f++){
                for(Ff=0;Ff<clas[F].stu[f].nbresub;Ff++)
                    free(clas[F].stu[f].sub[Ff].n);
                free(clas[F].stu[f].sub);
            }
            free(clas[F].stu);
        }
        free(clas);
        return 1;
    }
    fprintf(fl,"{\\rtf\\ansi\t \t  \t  \t\t\t\\b\\f0\\fs32\\ul %s %d\\ul0\\fs24\\b0 \\line\\line\\line",NE,YEAR);
    for(K=0;K<Cl;K++){
        fprintf(fl," \\line\t \t  \t  \t\t\t\\b\\f0\\fs28\\ul %s\\ul0\\b0\\fs24 \\line\\line\\line\\b\\ul HIGH MEAN:\\ul0\\b0  %.2f (%s %s) \\line\\b\\ul LOW MEAN:\\ul0\\b0  %.2f (%s %s) \\line\\line\\b\\ul NUMBER OF STUDENTS:\\ul0\\b0  %d STUDENTS  \\b\\ul PASS:\\ul0\\b0  %d STUDENTS  \\b\\ul FAIL:\\ul0\\b0  %d STUDENTS\\line\\line\\line\\line",clas[K].nom_cl,clas[K].moygma,clas[K].pegma,clas[K].negma,clas[K].moygmi,clas[K].pegmi,clas[K].negmi,clas[K].nbredetu,clas[K].nbra,clas[K].nbre);
    }
    fprintf(fl,"}");
    fclose(fl);
    free(NEY);
    for(K=0;K<Cl;K++){
        NEY=calloc(110,sizeof(char));
        sprintf(NEY,"%s%c%s",ney,SEP,clas[K].nom_cl);
        MKDIR(NEY);
        free(NEY);
        NEY=calloc(135,sizeof(char));
        sprintf(NEY,"%s%c%s%c%s.rtf",ney,SEP,clas[K].nom_cl,SEP,clas[K].nom_cl);
        if((fl=fopen(NEY,"wb"))==NULL){
            printf("FILE CREATING ERROR");
            for(F=0;F<Cl;F++){
                for(f=0;f<clas[F].nbredetu;f++){
                    for(Ff=0;Ff<clas[F].stu[f].nbresub;Ff++)
                         free(clas[F].stu[f].sub[Ff].n);
                    free(clas[F].stu[f].sub);
                }
                free(clas[F].stu);
            }
            free(clas);
            return 1;
        }
        fprintf(fl,"{\\rtf\\ansi");
        for(I=0;I<clas[K].nbredetu;I++){
            fprintf(fl,"\\b\\ul LAST NAME:\\ul0\\b0 %s \\line\\line\\b\\ul FIRST NAME:\\ul0\\b0\\fs24 %s\t\t\t\t\\b\\ul ID:\\ul0\\b0\\fs24 %ld \\line\\line\\b\\ul HIGH MEAN:\\ul0\\b0 %.2f IN %s\t\t\\b\\ul LOW MEAN \\ul0\\b0: %.2f IN %s \\line\\line\t\t\\b\\fs28 %d \\fs24 SUBJECTS VALIDATE / \\fs28 %d \\fs24 SUBJECTS\\b0 \\line\\line\\b\\ul SUM OF COEF MEAN:\\ul0\\b0 %.2f\t \t\\b\\ul GENERAL MEAN:\\ul0\\b0 %.2f \\line\\line\\line\\line",clas[K].stu[I].nom,clas[K].stu[I].pre,clas[K].stu[I].ID,clas[K].stu[I].moyma,clas[K].stu[I].nma,clas[K].stu[I].moymi,clas[K].stu[I].nmi,clas[K].stu[I].nbreva,clas[K].stu[I].nbresub,clas[K].stu[I].sommoyC,clas[K].stu[I].moyg);
        }
        fprintf(fl,"}");
        fclose(fl);
        free(NEY);
    }
    for(K=0;K<Cl;K++){
        for(I=0;I<clas[K].nbredetu;I++){
            NEY=calloc(180,sizeof(char));
            sprintf(NEY,"%s%c%s%c%s %s.rtf",ney,SEP,clas[K].nom_cl,SEP,clas[K].stu[I].nom,clas[K].stu[I].pre);
            if((fl=fopen(NEY,"wb"))==NULL){
                printf("FILE CREATING ERROR");
                for(F=0;F<Cl;F++){
                    for(f=0;f<clas[F].nbredetu;f++){
                        for(Ff=0;Ff<clas[F].stu[f].nbresub;Ff++)
                            free(clas[F].stu[f].sub[Ff].n);
                        free(clas[F].stu[f].sub);
                    }
                    free(clas[F].stu);
                }
                free(clas);
                return 1;
            }
            fprintf(fl,"{\\rtf\\ansi");
            for(J=0;J<clas[K].stu[I].nbresub;J++){
                fprintf(fl,"\t\t\t\t\t\t\\b\\ul\\fs34 %s\\ul0\\b0\\line\\line\\line\t\t\t\t\t\t\\b\\f0\\fs33\\ul NOTES\\ul0 \\b0 \\line\\line",clas[K].stu[I].sub[J].nom);
                if(clas[K].stu[I].sub[J].nbreno==3){
                    fprintf(fl,"\t");
                }
                if(clas[K].stu[I].sub[J].nbreno==2){
                    fprintf(fl,"\t\t\t");
                }
                if(clas[K].stu[I].sub[J].nbreno==1){
                    fprintf(fl,"\t\t\t\t\t");
                }
                for(L=0;L<clas[K].stu[I].sub[J].nbreno;L++){
                    if(L%3==0){
                        fprintf(fl,"\\line");
                    }
                    fprintf(fl,"\t\\fs32 %.2f\t\t",clas[K].stu[I].sub[J].n[L]);
                }
                fprintf(fl,"\\line\\line\\b\\f0\\fs30\\ul TOTAL:\\ul0\\b0\\fs28 %.2f \\line\\line\\b\\ul\\fs30 MEAN:\\ul0\\b0\\fs28 %.2f \t\\b\\ul\\fs30 COEF:\\ul0\\b0\\fs28 %d\t\\b\\ul\\fs30 COEF MEAN:\\ul0\\b0\\fs28 %.2f \\fs24\\line\\line",clas[K].stu[I].sub[J].somnot,clas[K].stu[I].sub[J].moy,clas[K].stu[I].sub[J].Coef,clas[K].stu[I].sub[J].moyC);
            }
            fprintf(fl,"\t\t\t\t\t\t\\b\\ul\\fs28 DECISION:\\ul0\\b0\\fs30\\b\\i %s\\i0\\b\\fs28\\line\\line\\line\\line}",clas[K].stu[I].dec);
            fclose(fl);
            free(NEY);
        }
    }
    for(F=0;F<Cl;F++){
        for(f=0;f<clas[F].nbredetu;f++){
            for(Ff=0;Ff<clas[F].stu[f].nbresub;Ff++)
                 free(clas[F].stu[f].sub[Ff].n);
            free(clas[F].stu[f].sub);
        }
        free(clas[F].stu);
    }
    free(clas);
    printf("ALL DATA ARE SAVED IN FOLDER %s AT THE LOCATION OF THE C PROGRAM",ney);
    free(ney);
    return 0;
}

