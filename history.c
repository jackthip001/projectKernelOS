#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sched.h>

struct task_struct *task;

int history_init(void) {

	for_each_process(task){
		printk(KERN_INFO "pc_name : %s, pc_state : %ld, pc_id : %d\n", task->comm, task->state, 2task->pid);
	}

	printk(KERN_INFO "Loading Birthday Module\n");
	return 0;
}

void history_exit(void) {

	printk(KERN_INFO "Removing Birthday Module\n");
}

module_init(history_init);
module_exit(history_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");