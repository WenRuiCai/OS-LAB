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
int x = 0;
int cur_time = 0;
/*void sched_yield(void)
{
    static struct Env *cur;
        //int i,count;
        //for (i=0,count=0;i<NENV;i++) {
        //      if (envs[i].env_status == ENV_RUNNABLE) {
        //              printf("the id:%d env is runnable\n",envs[i].env_id);
        //              count++;
        //      }
        //}
        //printf("now there is runnable env %d\n",count);
    while (cur_time == 0) {
        if (LIST_FIRST(&env_sched_list[x]) == NULL) {
            x = 1 - x;
        }
        cur = LIST_FIRST(&env_sched_list[x]);
        cur_time = cur -> env_pri;
        LIST_REMOVE(cur, env_sched_link);
        LIST_INSERT_HEAD(&env_sched_list[1-x], cur, env_sched_link);
    }
    cur_time --;
    env_run(cur);
}*/
void sched_yield(void) {
        static int pos = -1;
        while(1){
                pos = (pos+1)%NENV;
                if(envs[pos].env_status==ENV_RUNNABLE){
                        env_run(&envs[pos]);
                }
        }
}
