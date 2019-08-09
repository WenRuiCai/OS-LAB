#include <env.h>
#include <pmap.h>
#include <printf.h>

/* Overview:
 *  Implement simple round-robin scheduling.
 *  Search through 'envs' for a runnable environment ,
 *  in circular fashion statrting after the previously running env,
 *  and switch to the first such environment found.
 *
 * Hints:
 *  The variable which is for counting should be defined as 'static'.
 */
/*void sched_yield(void)
{
        static int x = 0;
        static int cur_time = 0;
        static struct Env *cur;
    while (cur_time == 0) {
        if (LIST_FIRST(&env_sched_list[x]) == NULL) {
            x = 1 - x;
        }
        cur = LIST_FIRST(&env_sched_list[x]);
        cur_time = cur -> env_pri;
        LIST_REMOVE(cur, env_sched_link);
                if (cur->env_status == ENV_RUNNABLE)
                LIST_INSERT_HEAD(&env_sched_list[1-x], cur, env_sched_link);
    }
    cur_time --;
    env_run(cur);
}*/
void sched_yield(void) {
        static int x = 0;
        static int cur_time = 0;
        static struct Env *cur = NULL;
        if (!(LIST_FIRST(&env_sched_list[0]) == NULL &&
                LIST_FIRST(&env_sched_list[1]) == NULL)) {
                if (cur == NULL) {
                        if (LIST_FIRST(&env_sched_list[x]) == NULL) {
                                x = 1 - x;
                        }
                        cur = LIST_FIRST(&env_sched_list[x]);
                        cur_time = cur -> env_pri;
                }
                if (cur_time == 0) {
                        LIST_REMOVE(cur, env_sched_link);
                        LIST_INSERT_HEAD(&env_sched_list[1-x], cur, env_sched_link);
                        if (LIST_FIRST(&env_sched_list[x]) == NULL) {
                                x = 1 - x;
                        }
                        cur = LIST_FIRST(&env_sched_list[x]);
                        cur_time = cur -> env_pri;
                }
                cur_time --;
                env_run(cur);
        }
}

