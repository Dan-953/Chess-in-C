#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define righe 34
#define colonne 52

struct coord{
        char carattere;
        int posizione;
};

typedef struct coord coord;

struct pedina{
	char nome;
	char colore;
        int altezza;
        int lunghezza;
};

struct  casella{
	struct casella *n;
	struct casella *s;
	struct casella *e;
	struct casella *o;
	struct casella *ne;
	struct casella *no;
	struct casella *se;
	struct casella *so;
	struct pedina pedina;
};

struct casella *head = NULL;

char pedone = 'P';
char cavallo = 'H';
char alfiere = 'A';
char torre = 'T';
char regina = 'Q';
char re = 'K';
char bianco = 'w';
char nero = 'b';

const coord lettere[8] = {'a',3,'b',7,'c',11,'d',15,'e',19,'f',23,'g',27,'h',31};
const coord numeri[8] = {'1',5,'2',11,'3',17,'4',23,'5',29,'6',35,'7',41,'8',47};


void crea_scacchiera(struct casella **head){
	struct casella *n;
	struct casella *p;
	for(int i=0; i<4; i++){
		for(int j=0; j<8; j++){
			n = (struct casella*)malloc(sizeof(struct casella));
			n->pedina.nome = '-';
			if(i == 0){
				n->n = NULL;
				n->no = NULL;
				n->ne = NULL;
				if(j == 0){
					*head = n;
				}
			}
			if(j == 0){
				n->so = NULL;
				n->o = NULL;
				n->no = NULL;
				if(i != 0){
					p->s = n;
					n->n = p;
				}
			}
			else if(j == 7){
				n->se = NULL;
				n->e = NULL;
				n->ne = NULL;
			}
			if(j != 0){
				n->o = p;
				p->e = n;
				if(i != 0){
					p = p->n;
					p->se = n;
					n->no = p;
					p = p->e;
					p->s = n;
					n->n = p;
					n = n->o;
					n->ne = p;
					p->so = n;
					n = n->e;
				}
			}
			p = n;
		}
		for(int j=0; j<8; j++){
			n = (struct casella*)malloc(sizeof(struct casella));
			n->pedina.nome = '-';
			if(j == 0){
				p->s = n;
				n->n = p;
			}
                        if(i == 3){
                                n->s = NULL;
				n->so = NULL;
				n->se = NULL;
                        }
                        if(j == 7){
                                n->so = NULL;
                                n->o = NULL;
                                n->no = NULL;
                        }
                        else if(j == 0){
                                n->se = NULL;
                                n->e = NULL;
                                n->ne = NULL;
                        }
                        if(j != 0){
                                n->e = p;
                                p->o = n;
                                p = p->n;
                                p->so = n;
                                n->ne = p;
                                p = p->o;
                                p->s = n;
                                n->n = p;
                                n = n->e;
                                n->no = p;
                                p->se = n;
				n = n->o;
                        }
                        p = n;
		}
	}
}

void inizializza(struct casella *head){
	struct casella *scorri = head;
	struct pedina ped[32] = {'P','w',6,0,'P','w',6,1,'P','w',6,2,'P','w',6,3,'P','w',6,4,'P','w',6,5,'P','w',6,6,'P','w',6,7,'P','b',1,0,'P','b',1,1,'P','b',1,2,'P','b',1,3,'P','b',1,4,'P','b',1,5,'P','b',1,6,'P','b',1,7,'H','w',7,1,'H','w',7,6,'H','b',0,1,'H','b',0,6,'A','w',7,2,'A','w',7,5,'A','b',0,2,'A','b',0,5,'T','w',7,0,'T','w',7,7,'T','b',0,0,'T','b',0,7,'Q','w',7,4,'Q','b',0,4,'K','w',7,3,'K','b',0,3};
	while(scorri->s != NULL){
		while(scorri->e != NULL){
			scorri->pedina.nome = '-';
			scorri->pedina.colore = '-';
			scorri = scorri->e;
		}
		scorri->pedina.nome = '-';
        	scorri->pedina.colore = '-';
		scorri = scorri->s;
		while(scorri->o != NULL){
                        scorri->pedina.nome = '-';
                        scorri->pedina.colore = '-';
                        scorri = scorri->o;
                }
                scorri->pedina.nome = '-';
                scorri->pedina.colore = '-';
		if(scorri->s != NULL){
                	scorri = scorri->s;
		}
	}
	for(int i=0; i<32; i++){
		scorri = head;
		for(int j=0; j<ped[i].altezza; j++){
			scorri = scorri->s;
		}
		for(int j=0; j<ped[i].lunghezza; j++){
			scorri = scorri->e;
		}
		scorri->pedina = ped[i];
	}
}

void stampa_scacchiera(struct casella *head){
	char scacchiera [righe][colonne] = {"     1     2     3     4     5     6     7     8   \n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "a |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "b |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                   	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "c |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "d |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "e |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "f |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "g |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  |*****|     |*****|     |*****|     |*****|     |\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "h |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  |     |*****|     |*****|     |*****|     |*****|\n",
                                    	    "  +-----+-----+-----+-----+-----+-----+-----+-----+\n"};

	for(int i=0; i<4; i++){
		while(head->e != NULL){
			if(head->pedina.nome != '-'){
				scacchiera[lettere[head->pedina.altezza].posizione][numeri[head->pedina.lunghezza].posizione] = head->pedina.nome;
				scacchiera[lettere[head->pedina.altezza].posizione+1][numeri[head->pedina.lunghezza].posizione] = head->pedina.colore;
			}
			head = head->e;
		}
		if(head->pedina.nome != '-'){
			scacchiera[lettere[head->pedina.altezza].posizione][numeri[head->pedina.lunghezza].posizione] = head->pedina.nome;
                	scacchiera[lettere[head->pedina.altezza].posizione+1][numeri[head->pedina.lunghezza].posizione] = head->pedina.colore;
		}
		head = head->s;
		while(head->o != NULL){
			if(head->pedina.nome != '-'){
                        	scacchiera[lettere[head->pedina.altezza].posizione][numeri[head->pedina.lunghezza].posizione] = head->pedina.nome;
                        	scacchiera[lettere[head->pedina.altezza].posizione+1][numeri[head->pedina.lunghezza].posizione] = head->pedina.colore;
                        }
			head = head->o;
                }
		if(head->pedina.nome != '-'){
			scacchiera[lettere[head->pedina.altezza].posizione][numeri[head->pedina.lunghezza].posizione] = head->pedina.nome;
                	scacchiera[lettere[head->pedina.altezza].posizione+1][numeri[head->pedina.lunghezza].posizione] = head->pedina.colore;
		}
		head = head->s;
	}
	for(int i=0; i<righe; i++){
                for(int j=0; j<colonne; j++){
                        printf("%c",scacchiera[i][j]);
                }
        }
}

struct casella* controlla_e_trova(struct casella *head, char input[], int turno){
	struct casella *trova = NULL;
	while(1){
		int colore = 0;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if((input[0] == lettere[i].carattere) && (input[1] == numeri[j].carattere)){
					trova = head;
					for(int k=0; k<i; k++){
						trova = trova->s;
					}
					for(int k=0; k<j; k++){
						trova = trova->e;
					}
				}
			}
		}
		if(trova != NULL && trova->pedina.nome != '-'){
			if(((turno == 0) && (trova->pedina.colore == nero)) || ((turno == 1) && (trova->pedina.colore == bianco))){
				colore = 1;
			}
			else{
				return trova;
			}
		}
		if(colore == 0){
			printf("Coordinate non valide, riprova.\n");
		}
		else{
			printf("La pedina non e' del tuo colore, riprova.\n");
		}
		scanf("%s",input);
	}
}

void trova(char input[],struct casella **mossa, int *altezza, int *lunghezza){
	struct casella *trova;
	*altezza = 0;
	*lunghezza = 0;
	for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                        if((input[0] == lettere[i].carattere) && (input[1] == numeri[j].carattere)){
                                trova = head;
                                for(int k=0; k<i; k++){
                                        trova = trova->s;
					*altezza+=1;
                                }
                                for(int k=0; k<j; k++){
                                        trova = trova->e;
					*lunghezza+=1;
                                }
				*mossa = trova;
				return;
                        }
			else{
				*mossa = NULL;
			}
                }
        }
}

void trova_casella(struct casella **trovato, char pedina, int turno){
	char colore;
	struct casella *scorri;
	int t = 0;
	if(turno == 0){
		colore = bianco;
	}
	else{
		colore = nero;
	}
	scorri = head;
	while(1){
		while(scorri->e != NULL){
			if(scorri->pedina.nome == pedina && scorri->pedina.colore == colore){
				t = 1;
				break;
			}
			scorri = scorri->e;
		}
		if(scorri->pedina.nome == pedina && scorri->pedina.colore == colore){
                	t = 1;
                        break;
                }
		scorri = scorri->s;
		while(scorri->o != NULL && t == 0){
			if(scorri->pedina.nome == pedina && scorri->pedina.colore == colore){
                                t = 1;
				break;
                        }
			scorri = scorri->o;
		}
		if(scorri->pedina.nome == pedina && scorri->pedina.colore == colore){
                        t = 1;
                	break;
                }
		if(scorri->s == NULL && t == 0){
			scorri = NULL;
			break;
		}
		else if(t == 1){
			break;
		}
	}
	*trovato = scorri;
}

void salva(struct casella *head,int turno){
	struct casella *scorri;
	FILE *f;
	f = fopen("salvataggio.txt","w");
	fprintf(f,"%d",turno);
	scorri = head;
	while(scorri->s != NULL){
		while(scorri->e != NULL){
			if(scorri->pedina.nome != '-'){
				fprintf(f,"%c %c %d %d ", scorri->pedina.nome, scorri->pedina.colore, scorri->pedina.altezza, scorri->pedina.lunghezza);
			}
			scorri = scorri->e;
		}
		if(scorri->pedina.nome != '-'){
                        fprintf(f,"%c %c %d %d ", scorri->pedina.nome, scorri->pedina.colore, scorri->pedina.altezza, scorri->pedina.lunghezza);
                }
		scorri = scorri->s;
		while(scorri->o != NULL){
			if(scorri->pedina.nome != '-'){
                        	fprintf(f,"%c %c %d %d ", scorri->pedina.nome, scorri->pedina.colore, scorri->pedina.altezza, scorri->pedina.lunghezza);
                        }
			scorri = scorri->o;
		}
		if(scorri->pedina.nome != '-'){
                	fprintf(f,"%c %c %d %d ", scorri->pedina.nome, scorri->pedina.colore, scorri->pedina.altezza, scorri->pedina.lunghezza);
                }
		if(scorri->s != NULL){
			scorri = scorri->s;
		}
	}
	fclose(f);
}

void carica(struct casella *head, int *t){
	struct casella *scorri = head;
	struct pedina inserisci;
	while(scorri->s != NULL){
                while(scorri->e != NULL){
                        scorri->pedina.nome = '-';
                        scorri->pedina.colore = '-';
                        scorri = scorri->e;
                }
                scorri->pedina.nome = '-';
                scorri->pedina.colore = '-';
                scorri = scorri->s;
                while(scorri->o != NULL){
                        scorri->pedina.nome = '-';
                        scorri->pedina.colore = '-';
                        scorri = scorri->o;
                }
                scorri->pedina.nome = '-';
                scorri->pedina.colore = '-';
                if(scorri->s != NULL){
                        scorri = scorri->s;
                }
        }
	FILE *f = fopen("salvataggio.txt","r");
	if(f == NULL){
		printf("Non e' presente alcun salvataggio.\n");
		exit(1);
	}
	fscanf(f,"%d",t);
	while(fscanf(f,"%c %c %d %d ",&inserisci.nome,&inserisci.colore,&inserisci.altezza,&inserisci.lunghezza) != EOF){
		scorri = head;
		for(int i=0; i<inserisci.altezza; i++){
			scorri = scorri->s;
		}
		for(int i=0; i<inserisci.lunghezza; i++){
			scorri = scorri->e;
		}
		scorri->pedina.nome = inserisci.nome;
		scorri->pedina.colore = inserisci.colore;
		scorri->pedina.altezza = inserisci.altezza;
		scorri->pedina.lunghezza = inserisci.lunghezza;
	}
	fclose(f);
}

int mosse_pedone(struct casella *pedone){
	struct casella *mossa;
	struct casella *uno, *due, *sinistra, *destra;
	char avversario = '-';
	int due_passi = 0, altezza = 0, lunghezza = 0, conta = 0, massimo;
	char input[9] = "---------";
	char colore[7] = "-------";
	if(((pedone->pedina.altezza == 6) && (pedone->pedina.colore == bianco)) || ((pedone->pedina.altezza == 1) && (pedone->pedina.colore == nero))){
		due_passi = 1;
	}
	if(pedone->pedina.colore == bianco){
		avversario = nero;
		strcpy(colore,"bianco");
		massimo = 0;
		if(pedone->n != NULL){
			uno = pedone->n;
		}
		if(uno->n != NULL){
			due = uno->n;
		}
		if(pedone->no != NULL){
			sinistra = pedone->no;
		}
		else{
			sinistra = NULL;
		}
		if(pedone->ne != NULL){
			destra = pedone->ne;
		}
		else{
			destra = NULL;
		}
	}
	else{
		avversario = bianco;
		strcpy(colore,"nero");
		massimo = 7;
		if(pedone->s != NULL){
			uno = pedone->s;
		}
		if(uno->s != NULL){
			due = uno->s;
		}
		if(pedone->so != NULL){
			sinistra = pedone->so;
		}
		else{
                        sinistra = NULL;
                }
		if(pedone->se != NULL){
			destra = pedone->se;
		}
		else{
                        destra = NULL;
                }
	}
	do{
		if(conta == 0){
			printf("Dove vuoi posizionare il pedone ? ");
        	}
		else{
			printf("Mossa non valida, riprova. ");
		}
		printf("(Scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
		conta = 1;
		scanf("%s",input);
		if(strcmp(input,"indietro") == 0){
			return 1;
		}
		else if(strcmp(input,"salva") == 0){
			return 2;
		}
		else if(strcmp(input,"esci") == 0){
			return 3;
		}
		trova(input,&mossa,&altezza,&lunghezza);
	}
	while(mossa == NULL || (uno != mossa || mossa->pedina.nome != '-') && (due != mossa || due_passi != 1 || mossa->pedina.nome != '-' || uno->pedina.nome != '-') && ((sinistra != mossa || (mossa->pedina.colore != avversario || mossa->pedina.nome == '-')) && (destra != mossa || (mossa->pedina.colore != avversario || mossa->pedina.nome == '-'))));
	if(sinistra == mossa || destra == mossa){
		printf("Congratulazioni, il pedone %s ha appena mangiato una pedina avversaria.\n",colore);
	}
	if(altezza == massimo){
		mossa->pedina.nome = regina;
	}
	else{
		mossa->pedina.nome = pedone->pedina.nome;
	}
	mossa->pedina.colore = pedone->pedina.colore;
	mossa->pedina.altezza = altezza;
	mossa->pedina.lunghezza = lunghezza;
	pedone->pedina.nome = '-';
	return 0;
}

int mosse_cavallo(struct casella *cavallo){
	struct casella *mossa;
	struct casella *no, *ne, *se, *so;
        char avversario = '-';
        int altezza = 0, lunghezza = 0, conta = 0;
        char input[9] = "---------";
        char colore[7] = "-------";
	if(cavallo->pedina.colore == bianco){
		avversario = nero;
		strcpy(colore,"bianco");
	}
	else{
		avversario = bianco;
		strcpy(colore,"nero");
	}
	if(cavallo->no != NULL){
		no = cavallo->no;
	}
	else{
		no = NULL;
	}
	if(cavallo->ne != NULL){
                ne = cavallo->ne;
        }
	else{
		ne = NULL;
	}
	if(cavallo->se != NULL){
                se = cavallo->se;
        }
	else{
		se = NULL;
	}
	if(cavallo->so != NULL){
                so = cavallo->so;
        }
	else{
		so = NULL;
	}
	do{
                if(conta == 0){
                        printf("Dove vuoi posizionare il cavallo ? ");
                }
                else{
                        printf("Mossa non valida, riprova. ");
                }
		printf("(Scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
                conta = 1;
                scanf("%s",input);
                if(strcmp(input,"indietro") == 0){
                        return 1;
                }
		else if(strcmp(input,"salva") == 0){
                        return 2;
                }
		else if(strcmp(input,"esci") == 0){
                        return 3;
                }
                trova(input,&mossa,&altezza,&lunghezza);
        }
        while(mossa == NULL || (no == NULL || ((mossa != no->n && mossa != no->o) || (mossa->pedina.nome != '-' && mossa->pedina.colore != avversario))) && (ne == NULL || ((mossa != ne->n && mossa != ne->e) || (mossa->pedina.nome != '-' && mossa->pedina.colore != avversario))) && (se == NULL || ((mossa != se->s && mossa != se->e) || (mossa->pedina.nome != '-' && mossa->pedina.colore != avversario))) && (so == NULL || ((mossa != so->s && mossa != so->o) || (mossa->pedina.nome != '-' && mossa->pedina.colore != avversario))));
	if(mossa->pedina.colore == avversario){
		printf("Congratulazioni, il cavallo %s ha appena mangiato una pedina avversaria.\n",colore);
	}
	mossa->pedina.nome = cavallo->pedina.nome;
        mossa->pedina.colore = cavallo->pedina.colore;
        mossa->pedina.altezza = altezza;
        mossa->pedina.lunghezza = lunghezza;
        cavallo->pedina.nome = '-';
	return 0;
}

int mosse_alfiere(struct casella *alfiere){
	struct casella *mossa;
	struct casella *scorri;
        char avversario = '-';
        int altezza = 0, lunghezza = 0, fine = 0;
        char input[9] = "---------";
        char colore[7] = "-------";
	if(alfiere->pedina.colore == bianco){
                avversario = nero;
                strcpy(colore,"bianco");
        }
        else{
                avversario = bianco;
                strcpy(colore,"nero");
        }
	printf("Dove vuoi posizionare l'alfiere ? (scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
	scanf("%s",input);
	if(strcmp(input,"indietro") == 0){
		return 1;
	}
	else if(strcmp(input,"salva") == 0){
                return 2;
        }
	else if(strcmp(input,"esci") == 0){
                return 3;
        }
	trova(input,&mossa,&altezza,&lunghezza);
	while(fine == 0){
		scorri = alfiere;
		while(scorri->no != NULL && (scorri->no->pedina.nome == '-' || scorri->no->pedina.colore == avversario)){
			if(scorri->no == mossa){
				fine = 1;
				break;
			}
			else{
				scorri = scorri->no;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
					break;
				}
			}
		}
		scorri = alfiere;
		while(scorri->ne != NULL && fine == 0 && (scorri->ne->pedina.nome == '-' || scorri->ne->pedina.colore == avversario)){
			if(scorri->ne == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->ne;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = alfiere;
		while(scorri->se != NULL && fine == 0 && (scorri->se->pedina.nome == '-' || scorri->se->pedina.colore == avversario)){
			if(scorri->se == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->se;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = alfiere;
		while(scorri->so != NULL && fine == 0 && (scorri->so->pedina.nome == '-' || scorri->so->pedina.colore == avversario)){
			if(scorri->so == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->so;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		if(fine == 0){
			printf("Mossa non valida, riprova. (scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
			scanf("%s",input);
			if(strcmp(input,"indietro") == 0){
				return 1;
			}
			else if(strcmp(input,"salva") == 0){
                        	return 2;
                	}
			else if(strcmp(input,"esci") == 0){
                        	return 3;
                	}
			trova(input,&mossa,&altezza,&lunghezza);
		}
	}
	if(mossa->pedina.colore == avversario){
                printf("Congratulazioni, l'alfiere %s ha appena mangiato una pedina avversaria.\n",colore);
        }
        mossa->pedina.nome = alfiere->pedina.nome;
        mossa->pedina.colore = alfiere->pedina.colore;
        mossa->pedina.altezza = altezza;
        mossa->pedina.lunghezza = lunghezza;
        alfiere->pedina.nome = '-';
	return 0;
}

int mosse_torre(struct casella *torre){
	struct casella *mossa;
	struct casella *scorri;
        char avversario = '-';
        int altezza = 0, lunghezza = 0, fine = 0;
        char input[9] = "---------";
        char colore[7] = "-------";
	if(torre->pedina.colore == bianco){
                avversario = nero;
                strcpy(colore,"bianca");
        }
        else{
                avversario = bianco;
                strcpy(colore,"nera");
        }
	printf("Dove vuoi posizionare la torre ? (scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
	scanf("%s",input);
	if(strcmp(input,"indietro") == 0){
		return 1;
	}
	else if(strcmp(input,"salva") == 0){
                return 2;
        }
	else if(strcmp(input,"esci") == 0){
                return 3;
        }
	trova(input,&mossa,&altezza,&lunghezza);
	while(fine == 0){
		scorri = torre;
		while(scorri->n != NULL && (scorri->n->pedina.nome == '-' || scorri->n->pedina.colore == avversario)){
			if(scorri->n == mossa){
				fine = 1;
				break;
			}
			else{
				scorri = scorri->n;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
					break;
				}
			}
		}
		scorri = torre;
		while(scorri->e != NULL && fine == 0 && (scorri->e->pedina.nome == '-' || scorri->e->pedina.colore == avversario)){
			if(scorri->e == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->e;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = torre;
		while(scorri->s != NULL && fine == 0 && (scorri->s->pedina.nome == '-' || scorri->s->pedina.colore == avversario)){
			if(scorri->s == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->s;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = torre;
		while(scorri->o != NULL && fine == 0 && (scorri->o->pedina.nome == '-' || scorri->o->pedina.colore == avversario)){
			if(scorri->o == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->o;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		if(fine == 0){
			printf("Mossa non valida, riprova. (scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
			scanf("%s",input);
			if(strcmp(input,"indietro") == 0){
				return 1;
			}
			else if(strcmp(input,"salva") == 0){
                        	return 2;
                	}
			else if(strcmp(input,"esci") == 0){
                        	return 3;
                	}
			trova(input,&mossa,&altezza,&lunghezza);
		}
	}
	if(mossa->pedina.colore == avversario){
                printf("Congratulazioni, la torre %s ha appena mangiato una pedina avversaria.\n",colore);
        }
        mossa->pedina.nome = torre->pedina.nome;
        mossa->pedina.colore = torre->pedina.colore;
        mossa->pedina.altezza = altezza;
        mossa->pedina.lunghezza = lunghezza;
        torre->pedina.nome = '-';
	return 0;
}

int mosse_regina(struct casella *regina){
	struct casella *mossa;
	struct casella *scorri;
        char avversario = '-';
        int altezza = 0, lunghezza = 0, fine = 0;
        char input[9] = "---------";
        char colore[7] = "-------";
	if(regina->pedina.colore == bianco){
                avversario = nero;
                strcpy(colore,"bianca");
        }
        else{
                avversario = bianco;
                strcpy(colore,"nera");
        }
	printf("Dove vuoi posizionare la regina ? (scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
	scanf("%s",input);
	if(strcmp(input,"indietro") == 0){
		return 1;
	}
	else if(strcmp(input,"salva") == 0){
                return 2;
        }
	else if(strcmp(input,"esci") == 0){
        	return 3;
        }
	trova(input,&mossa,&altezza,&lunghezza);
	while(fine == 0){
		scorri = regina;
		while(scorri->no != NULL && (scorri->no->pedina.nome == '-' || scorri->no->pedina.colore == avversario)){
			if(scorri->no == mossa){
				fine = 1;
				break;
			}
			else{
				scorri = scorri->no;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
					break;
				}
			}
		}
		scorri = regina;
		while(scorri->ne != NULL && fine == 0 && (scorri->ne->pedina.nome == '-' || scorri->ne->pedina.colore == avversario)){
			if(scorri->ne == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->ne;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = regina;
		while(scorri->se != NULL && fine == 0 && (scorri->se->pedina.nome == '-' || scorri->se->pedina.colore == avversario)){
			if(scorri->se == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->se;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = regina;
		while(scorri->so != NULL && fine == 0 && (scorri->so->pedina.nome == '-' || scorri->so->pedina.colore == avversario)){
			if(scorri->so == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->so;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = regina;
		while(scorri->n != NULL && (scorri->n->pedina.nome == '-' || scorri->n->pedina.colore == avversario)){
			if(scorri->n == mossa){
				fine = 1;
				break;
			}
			else{
				scorri = scorri->n;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
					break;
				}
			}
		}
		scorri = regina;
		while(scorri->e != NULL && fine == 0 && (scorri->e->pedina.nome == '-' || scorri->e->pedina.colore == avversario)){
			if(scorri->e == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->e;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = regina;
		while(scorri->s != NULL && fine == 0 && (scorri->s->pedina.nome == '-' || scorri->s->pedina.colore == avversario)){
			if(scorri->s == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->s;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		scorri = regina;
		while(scorri->o != NULL && fine == 0 && (scorri->o->pedina.nome == '-' || scorri->o->pedina.colore == avversario)){
			if(scorri->o == mossa){
                                fine = 1;
                                break;
                        }
                        else{
                                scorri = scorri->o;
				if(scorri->pedina.nome != '-' && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
                }
		if(fine == 0){
			printf("Mossa non valida, riprova. (scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
			scanf("%s",input);
			if(strcmp(input,"indietro") == 0){
				return 1;
			}
			else if(strcmp(input,"salva") == 0){
                        	return 2;
                	}
			else if(strcmp(input,"esci") == 0){
                        	return 3;
                	}
			trova(input,&mossa,&altezza,&lunghezza);
		}
	}
	if(mossa->pedina.colore == avversario){
                printf("Congratulazioni, la regina %s ha appena mangiato una pedina avversaria.\n",colore);
        }
        mossa->pedina.nome = regina->pedina.nome;
        mossa->pedina.colore = regina->pedina.colore;
        mossa->pedina.altezza = altezza;
        mossa->pedina.lunghezza = lunghezza;
        regina->pedina.nome = '-';
	return 0;
}

int mosse_re(struct casella *re, int matto[]){
	struct casella *mossa;
        struct casella *scorri;
        char avversario = '-';
        int altezza = 0, lunghezza = 0, conta = 0;
        char input[9] = "---------";
        char colore[7] = "-------";
        if(re->pedina.colore == bianco){
                avversario = nero;
                strcpy(colore,"bianco");
        }
        else{
                avversario = bianco;
                strcpy(colore,"nero");
        }
	do{
                if(conta == 0){
                        printf("Dove vuoi posizionare il re ? ");
                }
                else{
                        printf("Mossa non valida, riprova. ");
                }
                printf("(Scrivi 'indietro' per cambiare pedina, 'salva' per salvare oppure 'esci' per tornare al menu')\n");
                conta = 1;
                scanf("%s",input);
                if(strcmp(input,"indietro") == 0){
                        return 1;
                }
                else if(strcmp(input,"salva") == 0){
                        return 2;
                }
		else if(strcmp(input,"esci") == 0){
                        return 3;
                }
                trova(input,&mossa,&altezza,&lunghezza);
        }
	while(mossa == NULL || (mossa->pedina.nome != '-' && (mossa->pedina.colore != avversario || mossa->pedina.nome == '-')) || ((mossa != re->no || matto[0] != 0) && (mossa != re->n || matto[1] != 0) && (mossa != re->ne || matto[2] != 0) && (mossa != re->e || matto[3] != 0) && (mossa != re->se || matto[4] != 0) && (mossa != re->s || matto[5] != 0) && (mossa != re->so || matto[6] != 0) && (mossa != re->o || matto[7] != 0)));
	if(mossa->pedina.nome != '-' && mossa->pedina.colore == avversario){
                printf("Congratulazioni, il re %s ha appena mangiato una pedina avversaria.\n",colore);
        }
        mossa->pedina.nome = re->pedina.nome;
        mossa->pedina.colore = re->pedina.colore;
        mossa->pedina.altezza = altezza;
        mossa->pedina.lunghezza = lunghezza;
        re->pedina.nome = '-';
	return 0;
}

struct casella* controlla_incidenza(struct casella *casella, int turno){		//controlla l'incidenza di tutte le traiettorie delle pedine del turno attuale con una casella passata come parametro e restituisce eventualmente il puntatore alla pedina che interseca la casella
	struct casella *pedina[9], *destra, *sinistra, *scorri;
	char avversario;
	if(turno == 0){
		avversario = nero;
	}
	else{
		avversario = bianco;
	}

//                      PEDONE
        for(int i=0; i<7; i++){
                trova_casella(&pedina[i],pedone,turno);
                if(pedina[i] != NULL){
                        pedina[i]->pedina.nome = '-';
                }
        }
        trova_casella(&pedina[7],pedone,turno);

        for(int i=0; i<7; i++){
               	if(pedina[i] != NULL){
               	        pedina[i]->pedina.nome = pedone;
               	}
        }

       	for(int i=0; i<8; i++){
       	        if(pedina[i] != NULL){
       	                if(turno == 0){
       	                        destra = pedina[i]->ne;
       	                        sinistra = pedina[i]->no;
       	                }
       	                else{
       	                        destra = pedina[i]->se;
       	                        sinistra = pedina[i]->so;
       	                }
       	        }
       	        if(pedina[i] != NULL && (destra != NULL || sinistra != NULL)){
       	                if(destra == casella || sinistra == casella){
       	                        return pedina[i];
       	                }
		}
	}
//				CAVALLO
	trova_casella(&pedina[0],cavallo,turno);
	if(pedina[0] != NULL){
		pedina[0]->pedina.nome = '-';
	}
	trova_casella(&pedina[1],cavallo,turno);
	if(pedina[0] != NULL){
		pedina[0]->pedina.nome = cavallo;
	}

	for(int i=0; i<2; i++){
		if(pedina[i] != NULL){
			if((pedina[i]->no != NULL && pedina[i]->no->o == casella) || (pedina[i]->no != NULL && pedina[i]->no->n == casella) || (pedina[i]->ne != NULL && pedina[i]->ne->n == casella) || (pedina[i]->ne != NULL && pedina[i]->ne->e == casella) || (pedina[i]->se != NULL && pedina[i]->se->e == casella) || (pedina[i]->se != NULL && pedina[i]->se->s == casella) || (pedina[i]->so != NULL && pedina[i]->so->s == casella) || (pedina[i]->so != NULL && pedina[i]->so->o == casella)){
                                return pedina[i];
                        }
		}
	}
//				ALFIERE
	trova_casella(&pedina[0],alfiere,turno);
        if(pedina[0] != NULL){
                pedina[0]->pedina.nome = '-';
        	trova_casella(&pedina[1],alfiere,turno);
        	pedina[0]->pedina.nome = alfiere;
        }

	for(int i=0; i<2; i++){
                if(pedina[i] != NULL){
			scorri = pedina[i];
			while(scorri->no != NULL && (scorri->no->pedina.nome == '-' || scorri->no->pedina.nome == re || scorri->no->pedina.colore != avversario)){
				scorri = scorri->no;
				if(scorri == casella){
					return pedina[i];
				}
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
			}
			scorri = pedina[i];
			while(scorri->ne != NULL && (scorri->ne->pedina.nome == '-' || scorri->ne->pedina.nome == re || scorri->ne->pedina.colore != avversario)){
                                scorri = scorri->ne;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->se != NULL && (scorri->se->pedina.nome == '-' || scorri->se->pedina.nome == re || scorri->se->pedina.colore != avversario)){
                                scorri = scorri->se;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->so != NULL && (scorri->so->pedina.nome == '-' || scorri->so->pedina.nome == re || scorri->so->pedina.colore != avversario)){
                                scorri = scorri->so;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
		}
	}
//			TORRE
	trova_casella(&pedina[0],torre,turno);
        if(pedina[0] != NULL){
                pedina[0]->pedina.nome = '-';
		trova_casella(&pedina[1],torre,turno);
        	pedina[0]->pedina.nome = torre;
	}

	for(int i=0; i<2; i++){
                if(pedina[i] != NULL){
			scorri = pedina[i];
			while(scorri->n != NULL && (scorri->n->pedina.nome == '-' || scorri->n->pedina.nome == re || scorri->n->pedina.colore != avversario)){
				scorri = scorri->n;
				if(scorri == casella){
					return pedina[i];
				}
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
			}
			scorri = pedina[i];
			while(scorri->e != NULL && (scorri->e->pedina.nome == '-' || scorri->e->pedina.nome == re || scorri->e->pedina.colore != avversario)){
                                scorri = scorri->e;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->s != NULL && (scorri->s->pedina.nome == '-' || scorri->s->pedina.nome == re || scorri->s->pedina.colore != avversario)){
                                scorri = scorri->s;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                        	}
                        }
			scorri = pedina[i];
			while(scorri->o != NULL && (scorri->o->pedina.nome == '-' || scorri->o->pedina.nome == re || scorri->o->pedina.colore != avversario)){
                                scorri = scorri->o;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
		}
	}
//			REGINA
	for(int i=0; i<8; i++){
                trova_casella(&pedina[i],regina,turno);
                if(pedina[i] != NULL){
                        pedina[i]->pedina.nome = '-';
                }
        }
        trova_casella(&pedina[8],regina,turno);

        for(int i=0; i<8; i++){
               	if(pedina[i] != NULL){
               	        pedina[i]->pedina.nome = regina;
               	}
        }
	for(int i=0; i<9; i++){
                if(pedina[i] != NULL){
			scorri = pedina[i];
			while(scorri->no != NULL && (scorri->no->pedina.nome == '-' || scorri->no->pedina.nome == re || scorri->no->pedina.colore != avversario)){
				scorri = scorri->no;
				if(scorri == casella){
					return pedina[i];
				}
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
			}
			scorri = pedina[i];
			while(scorri->ne != NULL && (scorri->ne->pedina.nome == '-' || scorri->ne->pedina.nome == re || scorri->ne->pedina.colore != avversario)){
                                scorri = scorri->ne;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->se != NULL && (scorri->se->pedina.nome == '-' || scorri->se->pedina.nome == re || scorri->se->pedina.colore != avversario)){
                                scorri = scorri->se;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->so != NULL && (scorri->so->pedina.nome == '-' || scorri->so->pedina.nome == re || scorri->so->pedina.colore != avversario)){
                                scorri = scorri->so;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->n != NULL && (scorri->n->pedina.nome == '-' || scorri->n->pedina.nome == re || scorri->n->pedina.colore != avversario)){
				scorri = scorri->n;
				if(scorri == casella){
					return pedina[i];
				}
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
			}
			scorri = pedina[i];
			while(scorri->e != NULL && (scorri->e->pedina.nome == '-' || scorri->e->pedina.nome == re || scorri->e->pedina.colore != avversario)){
                                scorri = scorri->e;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
			scorri = pedina[i];
			while(scorri->s != NULL && (scorri->s->pedina.nome == '-' || scorri->s->pedina.nome == re || scorri->s->pedina.colore != avversario)){
                                scorri = scorri->s;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                        	}
                        }
			scorri = pedina[i];
			while(scorri->o != NULL && (scorri->o->pedina.nome == '-' || scorri->o->pedina.nome == re || scorri->o->pedina.colore != avversario)){
                                scorri = scorri->o;
                                if(scorri == casella){
                                        return pedina[i];
                                }
                                if(scorri->pedina.nome != '-' && scorri->pedina.nome != re && scorri->pedina.colore == avversario){
                                        break;
                                }
                        }
		}
	}
//			RE
	trova_casella(&pedina[0],re,turno);
        if(casella != NULL){
        	if(pedina[0]->no == casella || pedina[0]->n == casella || pedina[0]->ne == casella || pedina[0]->e == casella || pedina[0]->se == casella || pedina[0]->s == casella || pedina[0]->so == casella || pedina[0]->o == casella){
                	return pedina[0];
                }
        }

	return NULL;		//casella non intercettata
}

int controlla_re(int matto[], int turno){
	int scacco = 0, fermo = 1;
	char nomi[8];
	struct casella *controllo_re, *attuale, *pedina;
	for(int i=0; i<8; i++){
		matto[i] = 0;
	}

	trova_casella(&controllo_re,re,turno);
	for(int i=0; i<8; i++){
                if(i == 0){
                        attuale = controllo_re->no;
		}
                else if(i == 1){
                        attuale = controllo_re->n;
                }
                else if(i == 2){
                        attuale = controllo_re->ne;
                }
                else if(i == 3){
                        attuale = controllo_re->e;
                }
                else if(i == 4){
                        attuale = controllo_re->se;
                }
                else if(i == 5){
                	attuale = controllo_re->s;
                }
                else if(i == 6){
                        attuale = controllo_re->so;
                }
                else{
                	attuale = controllo_re->o;
        	}
		if(attuale != NULL){
			if(attuale->pedina.nome != '-' && attuale->pedina.colore == controllo_re->pedina.colore){
				matto[i] = 2;
			}
		}
		else{
			matto[i] = 2;
		}
	}
	if(turno == 0){
		turno = 1;
	}
	else{
		turno = 0;
	}

	for(int i=0; i<8; i++){
                if(i == 0){
                        attuale = controllo_re->no;
                }
                else if(i == 1){
                        attuale = controllo_re->n;
                }
                else if(i == 2){
                        attuale = controllo_re->ne;
                }
                else if(i == 3){
                        attuale = controllo_re->e;
                }
                else if(i == 4){
                        attuale = controllo_re->se;
                }
                else if(i == 5){
                        attuale = controllo_re->s;
                }
                else if(i == 6){
                        attuale = controllo_re->so;
                }
                else{
                        attuale = controllo_re->o;
                }
                if(attuale != NULL){
			if(controlla_incidenza(attuale,turno) != NULL){
                                matto[i] = 1;
                        }
                }
	}
	pedina = controlla_incidenza(controllo_re,turno);
	if(pedina != NULL){
		scacco = 1;
	}

	for(int i=0; i<8; i++){
		fermo*=matto[i];
	}

	if(scacco == 1){
		if(fermo != 0){
			return 2;
		}
		return 1;
	}
	else{
		return 0;
	}
}

int re_solo(int turno){
	int i = 0;
	char colore;
	if(turno == 0){
		colore = bianco;
	}
	else{
		colore = nero;
	}
	struct casella *scorri = head;
	while(scorri->s != NULL){
		while(scorri->e != NULL){
			if(scorri->pedina.nome != re && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
				i++;
			}
			scorri = scorri->e;
		}
		if(scorri->pedina.nome != re && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                	i++;
                }
		scorri = scorri->s;
		while(scorri->o != NULL){
			if(scorri->pedina.nome != re && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                                i++;
                        }
                        scorri = scorri->o;
		}
		if(scorri->pedina.nome != re && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                        i++;
                }
		if(scorri->s != NULL){
			scorri = scorri->s;
		}
	}
	if(i == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int pedoni_bloccati(int turno){
	struct casella *pedoni[8], *avanti, *destra, *sinistra, *scorri = head;
	int i=0, accumula=1, solo_pedoni=0;
	char colore;
	if(turno == 0){
		colore = bianco;
	}
	else{
		colore = nero;
	}
	while(scorri->s != NULL){
                while(scorri->e != NULL){
                        if(scorri->pedina.nome != re && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                                i++;
                        }
                        scorri = scorri->e;
                }
                if(scorri->pedina.nome != re && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                        i++;
                }
                scorri = scorri->s;
                while(scorri->o != NULL){
                        if(scorri->pedina.nome != re && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                                i++;
                        }
                        scorri = scorri->o;
                }
                if(scorri->pedina.nome != re && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                        i++;
                }
                if(scorri->s != NULL){
                        scorri = scorri->s;
                }
        }
	if(i == 0){
		solo_pedoni = 1;
	}

	i=0;
	trova_casella(&pedoni[i],pedone,turno);
	while(pedoni[i] != NULL){
		pedoni[i]->pedina.nome = '-';
		i++;
		trova_casella(&pedoni[i],pedone,turno);
	}
	i=0;
	while(pedoni[i] != NULL){
		pedoni[i]->pedina.nome = pedone;
		i++;
	}
	i=0;
	while(pedoni[i] != NULL){
		if(turno == 0){
			avanti = pedoni[i]->n;
			destra = pedoni[i]->ne;
			sinistra = pedoni[i]->no;
		}
		else{
			avanti = pedoni[i]->s;
			destra = pedoni[i]->se;
			sinistra = pedoni[i]->so;
		}
		if((avanti == NULL || avanti->pedina.nome != '-') && (destra == NULL || destra->pedina.nome == '-') && (sinistra == NULL || sinistra->pedina.nome == '-')){
			accumula = 1;
		}
		else{
			accumula = 0;
		}
		accumula*=accumula;
		i++;
	}
	if(accumula == 1 && solo_pedoni == 1){
		return 1;
	}
	else if(accumula == 1){
		return 2;
	}
	else{
		return 0;
	}
}

int cavalli_bloccati(int turno){
	struct casella *cavalli[2], *no, *ne, *se, *so, *scorri = head;
        int i=0, accumula=1, solo_cavalli_e_pedoni=0;
        char colore;
        if(turno == 0){
                colore = bianco;
        }
        else{
                colore = nero;
        }
        while(scorri->s != NULL){
                while(scorri->e != NULL){
                        if(scorri->pedina.nome != re && scorri->pedina.nome != cavallo && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                                i++;
                        }
                        scorri = scorri->e;
                }
                if(scorri->pedina.nome != re && scorri->pedina.nome != cavallo && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                        i++;
                }
                scorri = scorri->s;
                while(scorri->o != NULL){
                        if(scorri->pedina.nome != re && scorri->pedina.nome != cavallo && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                                i++;
                        }
                        scorri = scorri->o;
                }
                if(scorri->pedina.nome != re && scorri->pedina.nome != cavallo && scorri->pedina.nome != pedone && scorri->pedina.nome != '-' && scorri->pedina.colore == colore){
                        i++;
                }
                if(scorri->s != NULL){
                        scorri = scorri->s;
                }
        }
        if(i == 0){
                solo_cavalli_e_pedoni = 1;
        }

	i=0;
        trova_casella(&cavalli[i],cavallo,turno);
        while(cavalli[i] != NULL){
                cavalli[i]->pedina.nome = '-';
                i++;
                trova_casella(&cavalli[i],cavallo,turno);
        }
        i=0;
        while(cavalli[i] != NULL){
                cavalli[i]->pedina.nome = cavallo;
                i++;
        }
	i=0;
        while(cavalli[i] != NULL){
                no = cavalli[i]->no;
                ne = cavalli[i]->ne;
                se = cavalli[i]->se;
		so = cavalli[i]->so;
                if((no == NULL || ((no->o == NULL || (no->o->pedina.nome != '-' && no->o->pedina.colore == cavalli[i]->pedina.colore)) && (no->n == NULL || (no->n->pedina.nome != '-' && no->n->pedina.colore == cavalli[i]->pedina.colore)))) && (ne == NULL || ((ne->n == NULL || (ne->n->pedina.nome != '-' && ne->n->pedina.colore == cavalli[i]->pedina.colore)) && (ne->e == NULL || (ne->e->pedina.nome != '-' && ne->e->pedina.colore == cavalli[i]->pedina.colore)))) && (se == NULL || ((se->e == NULL || (se->e->pedina.nome != '-' && se->e->pedina.colore == cavalli[i]->pedina.colore)) && (se->s == NULL || (se->s->pedina.nome != '-' && se->s->pedina.colore == cavalli[i]->pedina.colore)))) && (so == NULL || ((so->s == NULL || (so->s->pedina.nome != '-' && so->s->pedina.colore == cavalli[i]->pedina.colore)) && (so->o == NULL || (so->o->pedina.nome != '-' && so->o->pedina.colore == cavalli[i]->pedina.colore))))){
                        accumula = 1;
                }
                else{
                        accumula = 0;
                }
                accumula*=accumula;
                i++;
        }
        if(accumula == 1 && solo_cavalli_e_pedoni == 1 && pedoni_bloccati(turno) == 2){
                return 1;
        }
        else{
                return 0;
        }


}

int turno(int turno){
	char colore[7];
	int matto[8] = {0,0,0,0,0,0,0,0};
	char input[] = "---";
	struct casella *pedina = NULL;
	int feedback;
	if(turno == 0){
		strcpy(colore,"bianco");
	}
	else{
		strcpy(colore,"nero");
	}
	while(1){
		printf("Tocca al giocatore %s.\n",colore);
        	if(controlla_re(matto,turno) != 0){
			printf("Attenzione, il re e' sotto scacco!\n");
			if(re_solo(turno) == 1 || pedoni_bloccati(turno) == 1 || cavalli_bloccati(turno) == 1){
				if(controlla_re(matto,turno) == 2){
					return 1;
				}
				while(getchar() != '\n');
				printf("Ti arrendi ?\n");
				scanf("%s",input);
				if(strcmp(input,"si") == 0){
					return 1;
				}
			}
			while(getchar() != '\n');
                }
		printf("Inserisci le coordinate della pedina che vuoi muovere.\n");
		scanf("%s",input);
        	pedina = controlla_e_trova(head,input,turno);
        	if(pedina->pedina.nome == pedone){
                        feedback = mosse_pedone(pedina);
        	}
                else if(pedina->pedina.nome == cavallo){
			feedback = mosse_cavallo(pedina);
                }
                else if(pedina->pedina.nome == alfiere){
			feedback = mosse_alfiere(pedina);
                }
                else if(pedina->pedina.nome == torre){
			feedback = mosse_torre(pedina);
                }
                else if(pedina->pedina.nome == regina){
			feedback = mosse_regina(pedina);
                }
		else if(pedina->pedina.nome == re){
			feedback = mosse_re(pedina,matto);
		}
		if(feedback == 0 && controlla_re(matto,turno) == 2){
			return 1;
		}
		if(feedback == 1){
			stampa_scacchiera(head);
			continue;
		}
		else if(feedback == 2){
			salva(head,turno);
			printf("Partita salvata con successo.\n");
			continue;
		}
		else if(feedback == 3){
			return 2;
		}
		else{
			break;
		}
	}
}

void partita(int *t){
	int scacco_matto = 0;
	char colore[7];
        while(scacco_matto != 1){
                if(*t == 0){
                        scacco_matto = turno(*t);
			*t = 1;
                }
                else{
                        scacco_matto = turno(*t);
                	*t = 0;
		}
		if(scacco_matto != 1){
                stampa_scacchiera(head);
        	}
		if(scacco_matto == 2){
			return;
		}
	}
	if(*t == 0){
		strcpy(colore,"bianco");
	}
	else{
		strcpy(colore,"nero");
	}
	printf("------------------------------------------------------------\n\n");
	printf("Scacco matto!!!\nComplimenti giocatore %s, hai vinto !\n\n",colore);
	printf("------------------------------------------------------------\n\n");
}

void menu(int *scelta){
        int turno = 0;
	int conta = 0;
        while(1){
                printf("\n			IL GIOCO DGLI SCACCHI\n");
                printf("\n			'1' Nuova partita.\n			'2' Carica partita.\n			'3' Esci.\n");
                scanf("%d",scelta);
                if(*scelta == 1 || *scelta == 2 || *scelta == 3){
        		switch(*scelta){
                		case 1:
					if(conta == 0){
                        			crea_scacchiera(&head);
                        		}
					inizializza(head);
                        		stampa_scacchiera(head);
					turno = 0;
                        		partita(&turno);
                        		break;
                		case 2:
					if(conta == 0){
                        			crea_scacchiera(&head);
                        		}
					carica(head,&turno);
                        		stampa_scacchiera(head);
                        		partita(&turno);
                        		break;
        			case 3:
					exit(0);
					break;
			}
			conta = 1;
		}
	}
}

int main(){
        int scelta = 0;
        menu(&scelta);
}
