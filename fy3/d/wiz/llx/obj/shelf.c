// /d/wiz/llx/obj/shelf

inherit ITEM;
void create()
{        
        set_name("水晶书架", ({ "book shelf", "shelf", "书架"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "个");
                set("long", "一个由整块水晶制成的书架，摆满了各种书籍。上面好象还有些个人资料之类的东西\n");
                set("value", 1);
        }
}

int is_container() 
{
return 1;
}
