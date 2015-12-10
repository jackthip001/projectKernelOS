#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>

struct birthday {
	int day;
	int month;
	int year;
	struct list_head list;

};

static LIST_HEAD(birthday_list);

struct birthday *person, *ptr, *next;

int birthday_init(void) {

	int i;
	for(i = 0; i < 5 ; i++) {
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->day = 3+i;
		person->month = 8-i;
		person->year = 1995;
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &birthday_list);
	}
	
	list_for_each_entry(person, &birthday_list, list) {
		printk(KERN_INFO "day = %d, month = %d, year = %d",person->day, person->month, person->year);
	}

	printk(KERN_INFO "Loaded Birthday Module\n");

	return 0;
}

void birthday_exit(void){
	list_for_each_entry_safe(ptr, next, &birthday_list, list) {
		printk(KERN_INFO "removing entry");
		list_del(&ptr->list);
		kfree(ptr);
		
	}
	printk(KERN_INFO "Removing Birthday Module\n");
}

module_init(birthday_init);
module_exit(birthday_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");