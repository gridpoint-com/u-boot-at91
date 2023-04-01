#include <common.h>

char *get_cpu_name(void);

void at91_prepare_cpu_var(void)
{
	env_set("cpu", get_cpu_name());
}
