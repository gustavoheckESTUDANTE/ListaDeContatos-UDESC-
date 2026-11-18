#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

//código de identificação, nome, telefone e tipo do contato (pessoal ou trabalho).

static int incrementalId = 0;

void saveContact();

struct Contact {
    int id;
    char *nome;
    char *telefone;
    bool isProf;
};

int main () {
    optionsHandler();
    return 0;
};


void optionsHandler() {
    char optslctd;
    printf("Escolha uma das opções: | (C) Adicionar ) | (R) Listar | (U) Editar | (D) Remover | ");
    scanf("%d", &optslctd);
    switch (optslctd)
    {
    case constant expression:
        /* code */
        break;
    
    default:
        break;
    }
}








void saveContact() {

    FILE *db = fopen("database.json", "w");

    if (db == NULL) {
        printf("Erro ao abrir o banco de dados!\n");
        return;
    }

    struct Contact contact;

    contact.nome = malloc(255 * sizeof(char));
    contact.telefone = malloc(255 * sizeof(char));

    if (contact.nome == NULL || contact.telefone == NULL) {
        printf("Erro ao alocar memoria!\n");

        free(contact.nome);
        free(contact.telefone);
        fclose(db);

        return;
    }

    contact.id = ++incrementalId;

    printf("Digite seu nome:\n");
    scanf("%254s", contact.nome);

    printf("Digite o telefone:\n");
    scanf("%254s", contact.telefone);

    int answer;

    do {
        printf("Seu telefone e Pessoal ou de Trabalho?\n");
        printf("|1-Pessoal|2-Trabalho|\n");

        scanf("%d", &answer);

        if (answer < 1 || answer > 2) {
            printf("Valor invalido! Tente novamente.\n");
        }

    } while (answer < 1 || answer > 2);

    contact.isProf = (answer == 2);

    fprintf(db,
        "{\n"
        "  \"id\": %d,\n"
        "  \"nome\": \"%s\",\n"
        "  \"telefone\": \"%s\",\n"
        "  \"isProf\": %s\n"
        "}\n",
        contact.id,
        contact.nome,
        contact.telefone,
        contact.isProf ? "true" : "false"
    );

    free(contact.nome);
    free(contact.telefone);

    fclose(db);

    printf("Contato salvo com sucesso!\n");
}