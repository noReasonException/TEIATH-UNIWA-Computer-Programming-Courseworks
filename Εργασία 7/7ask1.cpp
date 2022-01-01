#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define FAIL NULL
#define SUCCESS 1
#define ERR 2
#define FOPEN_ERROR -1

/*
 * Συνάρτηση openfile()
 * Ανοίγει το αρχείο σε κατάσταση append ("a")
 * @:arg
 *      δεν λαμβάνει καμια παράμετρο
 * @:returns
 *      NULL σε περίπτωση αποτυχίας ανοίγματος αρχείου
 *      εναν δείκτη σε δεδομένα τύπου FILE (struct) assosiated με ενα αρχείο , το οποίο δείχνει στο τέλος (κατάσταση append)
 */
FILE *openfile() { return fopen("data.txt","a"); }
/*
 * Συνάρτηση writeintoopenedfile(FILE **,char **)
 * Γράφει πάνω στο αρχείο /Stream το οποίο δίνεται ως πρώτη παράμετρος , τα δεδομένα που δίνονται στον buffer (δευτερη παράμετρος)
 * Προσοχή! πρέπει να έχει ήδη ανοιχτεί το αρχειο /Stream πριν την κλήση της writeintofile και να εχε δεσμευτεί δυναμικα
 * ο buffer
 * @:arg
 *      FILE ** file_descriptor -> Εναν pointer προς pointers τύπου FILE
 *      char ** Buffer -> η περιοχή ενδιάμεσης μνήμης προς εγραφή
 * @:returns ακαίρεο (int)
 *      SUCCESS (1) Σε περίπτωση επιτυχίας
 *      ERR(2) Σε διαφορετική περίπτωση
 */
int writeintoopenedfile(FILE **file_descriptor,char **Buffer){
    fflush(*file_descriptor);
    if(fprintf(*file_descriptor,*Buffer)){
        return SUCCESS;
    }
    else return ERR;
}
/*
 * Συνάρτηση ΙΝΙΤ_ΜΕΜΟΡΥ(char **Buffer)
 * Κάνει τις απαραίτητες δεσμεύσεις στην μνήμη για την περιοχή ενδιάμεσης αποθήκευσης Buffer
 * @:arg
 *      char ** Buffer , εναν διπλο pointer προς την περιοχή ενδιάμεσης αποθήκευσης
 * @:no_returns (void)
 */
void INIT_MEMORY(char **Buffer){
    *Buffer=(char *)malloc(200*sizeof(char));
    if(*Buffer==FAIL){
        fprintf(stderr,"cant allocate memory!");
        exit(EXIT_FAILURE);
    }
    memset(*Buffer,0,200*sizeof(char));
}
/*
 * Σύνάρτηση EXIT_PROCCESS(File **file_pointer,char **Buffer)
 * Κάνει την απαραίτηση απελευθέρωση μνήμης και κλείνει το ρεύμα εξόδου που ανοίχτηκε με την openfile()
 * @:arg
 *        FILE **file_pointer -> ενα ανοιχτό stream προς αρχείο
 *        char **Buffer -> εναν pointer που δείχνει σε δυναμικα δεσμευμένο πίνακα!!!!
 * @:no_returns!
 *
 * @:warn
 *      το ρεύμα θα πρέπει να είναι ανοιγμένο με μια κληση της openfile()
 *      Η μνήμη πρέπει να είναι δυναμικά δεσμευμένη με μια κλήση της INIT_MEMORY
 *
 */
void EXIT_PROCCESS(FILE **file_pointer,char **Buffer){
    fclose(*file_pointer);
    free(*Buffer);
}

void Call_UI(char **Buffer,FILE **file_pointer){
    int num,i;
    size_t buffsize=200;//Δήλωση μεγέθους buffer (το size_t είναι ενα εσωτερικό typedef της c -> unsigned int)
    printf("Δώσε αριθμό μαθητών");
    scanf("%d",&num);
    for (i = 0; i <=num; ++i) {
        if(i==0){
            fflush(*file_pointer);
            getline(Buffer,&buffsize,stdin);
            continue;
        }
        printf("%d)Δώσε στοιχεία φοιτητη\n",i);
        fflush(stdin);
        getline(Buffer,&buffsize, stdin);

        if(writeintoopenedfile(file_pointer,Buffer)==SUCCESS){
            printf("%s -> [Success into data.txt]\n",*Buffer);
        }
        else{
            printf("%s -> [Error into data.txt\n",*Buffer);
        }
    }
}
int main() {
    char *Buffer;                              //Δήλωση Buffer
    FILE *file_pointer=openfile();            //Άνοιγμα αρχείου
    INIT_MEMORY(&Buffer);                    //Αρχικοποίηση Μνήμης
    Call_UI(&Buffer,&file_pointer);         //Κλήση συνάρτησης που υλοιποιεί το UserInterface
    EXIT_PROCCESS(&file_pointer,&Buffer);  //Εξοδος


}