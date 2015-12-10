#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sched.h>



void dfs_history(struct task_struct *task) {
	struct task_struct *next;
	struct list_head *list;
	list_for_each(list, &task->children) {
		next = list_entry(list, struct task_struct, sibling);
		printk(KERN_INFO "pc_name : %s, parent_id : %d, pc_state : %ld, pc_id : %d\n", next->comm, next->parent->pid, next->state, next->pid);
		dfs_history(next);
	}
}

int history_init(void) {

	printk(KERN_INFO "Loading Birthday Module\n");
	dfs_history(&init_task);
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