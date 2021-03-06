#define TRACE_MODULE _sgw_main

#include "core_debug.h"
#include "core_signal.h"
#include "core_semaphore.h"

#include "app/context.h"
#include "app/app.h"

const char *app_name = "sgw";

status_t app_initialize(const char *config_path, const char *log_path)
{
    status_t rv;
    int app = 0;

    rv = app_will_initialize(config_path, log_path);
    if (rv != CORE_OK) return rv;

    app = context_self()->logger.trace.app;
    if (app)
    {
        d_trace_level(&_sgw_main, app);
    }

    d_trace(1, "SGW try to initialize\n");
    rv = sgw_initialize();
    d_assert(rv == CORE_OK, return rv, "Failed to intialize SGW");
    d_trace(1, "SGW initialize...done\n");

    rv = app_did_initialize();
    if (rv != CORE_OK) return rv;

    return CORE_OK;
}

void app_terminate(void)
{
    app_will_terminate();

    d_trace(1, "SGW try to terminate\n");
    sgw_terminate();
    d_trace(1, "SGW terminate...done\n");

    app_did_terminate();
}
