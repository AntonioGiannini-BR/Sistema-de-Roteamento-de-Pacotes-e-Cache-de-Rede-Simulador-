
#include <stdio.h>
#include <string.h>
#include <microhttpd.h>

#define PORT 8888

const char *json =
"{"
"\"packets\":12,"
"\"cacheHits\":8,"
"\"collisions\":2,"
"\"priority\":6"
"}";

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

    response = MHD_create_response_from_buffer(
        strlen(json),
        (void*) json,
        MHD_RESPMEM_PERSISTENT
    );

    MHD_add_response_header(response,"Content-Type","application/json");
    MHD_add_response_header(response,"Access-Control-Allow-Origin","*");

    int ret = MHD_queue_response(connection,MHD_HTTP_OK,response);

    MHD_destroy_response(response);

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

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
