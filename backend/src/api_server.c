/*
 * Servidor HTTP simples do backend.
 * Ele expõe dados simulados do sistema em formato JSON para o frontend consumir.
 */

// Inclui bibliotecas e dependências necessárias para montar o servidor HTTP e gerar JSON.
#include <stdio.h>
#include <string.h>
#include <microhttpd.h>
#include <time.h>
#include <stdlib.h>

#define PORT 8888
#define MAX_RESPONSE 4096

// Estruturas de dados simuladas para demonstração
// Estrutura que reúne os dados estatísticos enviados para o frontend.
typedef struct {
  int id;
  char destination[50];
  int priority;
  char content[100];
} Packet;

typedef struct {
  int totalPackets;
  int priorityPackets;
  int collisions;
  int cacheHits;
  int cacheMiss;
  int processed;
  char hashType[50];
  char status[20];
} SystemStats;

// Função para gerar JSON com os dados do sistema
// Monta uma string JSON com os valores atuais das estatísticas do sistema.
char* generateJSON(SystemStats* stats) {
  static char json[MAX_RESPONSE];
  
  snprintf(json, MAX_RESPONSE,
    "{"
    "\"packets\":%d,"
    "\"cacheHits\":%d,"
    "\"collisions\":%d,"
    "\"priority\":%d,"
    "\"processed\":%d,"
    "\"cacheMiss\":%d,"
    "\"hashType\":\"%s\","
    "\"status\":\"%s\""
    "}",
    stats->totalPackets,
    stats->cacheHits,
    stats->collisions,
    stats->priorityPackets,
    stats->processed,
    stats->cacheMiss,
    stats->hashType,
    stats->status
  );
  
  return json;
}

// Dados globais do sistema (simulados)
// Dados globais simulados usados como resposta padrão da API.
SystemStats systemStats = {
  .totalPackets = 12,
  .priorityPackets = 6,
  .collisions = 2,
  .cacheHits = 8,
  .cacheMiss = 4,
  .processed = 12,
  .hashType = "Separate Chaining",
  .status = "online"
};

// Callback chamado pelo microhttpd sempre que uma requisição HTTP chega ao servidor.
enum MHD_Result answer_to_connection(
    void *cls,
    struct MHD_Connection *connection,
    const char *url,
    const char *method,
    const char *version,
    const char *upload_data,
    size_t *upload_data_size,
    void **con_cls)
{
    struct MHD_Response *response;
    char *json = generateJSON(&systemStats);

    // Cria uma resposta HTTP copiando o JSON gerado para o buffer de saída.
    response = MHD_create_response_from_buffer(
        strlen(json),
        (void*) json,
        MHD_RESPMEM_MUST_COPY
    );

        // Define os cabeçalhos para indicar JSON e permitir acesso pelo frontend.
    MHD_add_response_header(response,"Content-Type","application/json");
    MHD_add_response_header(response,"Access-Control-Allow-Origin","*");

    int ret = MHD_queue_response(connection,MHD_HTTP_OK,response);

    MHD_destroy_response(response);

    return ret;
}

// Inicializa o servidor HTTP e mantém a API ativa enquanto o programa estiver rodando.
int main() {
    struct MHD_Daemon *daemon;

    // Sobe o servidor na porta configurada para aceitar conexões do frontend.
    daemon = MHD_start_daemon(
        MHD_USE_INTERNAL_POLLING_THREAD,
        PORT,
        NULL,
        NULL,
        &answer_to_connection,
        NULL,
        MHD_OPTION_END
    );

    if (daemon == NULL)
        return 1;

    printf("API ONLINE: http://localhost:8888\n");

    getchar();

    MHD_stop_daemon(daemon);

    return 0;
}
