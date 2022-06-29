#ifndef _DES_H_
#define _DES_H_

#define ENCRYPTION_MODE 1 //Desncripta
#define DECRYPTION_MODE 0 //Encripta

typedef struct { 
	unsigned char k[8]; //llave original 
	unsigned char c[4]; //Parte derecha de la llave 
	unsigned char d[4]; //Parte izquierda de la llave
} key_set;

void generate_key(unsigned char* key); //operacion en des.c
void generate_sub_keys(unsigned char* main_key, key_set* key_sets); //operacion en des.c
void process_message(unsigned char* message_piece, unsigned char* processed_piece, key_set* key_sets, int mode); //operacion en des.c

#endif
