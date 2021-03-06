//d/wiz/llx/workroom.c

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
        set("short",HIW"李熙工作室"NOR);
        set("long", @LONG
屋内的灯光很柔和，让你感觉到非常舒适，在这里工作你一定会觉得非常惬
意。你有兴来到这里是你的运气，在这里你有兴可以看到李熙的一些个人详细资料。
屋子的中间有一张工作台，正对着你的墙上有一个书架，东南方是通往巫师会客厅
的大门。楼下是李熙的测试间，楼上是李熙的私人房间，没有经过同意请不要去那
里。还有就是请大家看看"注意事项"(paizi)。
LONG);
        set("exits", ([
        "down" :__DIR__"test",
        "up" :__DIR__"mishi",
        "southeast" : "/d/wiz/jobroom",
        "out" :"/d/fy/fysquare",
]));
        set("objects", ([ 
                __DIR__"obj/paizi" : 1,
                __DIR__"obj/table" : 1,
                __DIR__"obj/shelf" : 1,
        ]));
        set("no_beg",1);
        set("no_stearl",1);
        set("no_magic",1);
        set("no_huanlong",1);
        set("no_burn",1);
	set("no_death_penalty",1);
        
        set("coor/x",-500);
        set("coor/y",-500);
        set("coor/z",-500);
        setup();
}

void init()
{
        add_action("do_get", "get");
        add_action("do_qiurao", "qiurao");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;      

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) ==0) {
                item = new(__DIR__"obj/book",1);
                item->move(con);
                item = new(__DIR__"myobj/wuyoucha",2);
                item->move(con);
                item = new(__DIR__"myobj/xuejia",2);
                item->move(con);
        }
        con = present("book shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) ==0) {
                item = new(__DIR__"obj/dangan");
                item->move(con);
        }
}
int do_get(string arg)
{
        string          obj, from;
        object          me, shelf, table, target, taro;

        if(sscanf(arg, "%s from %s", obj, from)==2 ) {
                if(obj == "all") {
                        write("一次拿太多东西会被守卫发现的。\n");
                        return 1;
                }
                table =  present("table",this_object());
                shelf =  present("shelf",this_object());
                target =  present(from,this_object());
                me = this_player();
                if(target == table || target == shelf) {
                        taro =  present(obj, target);
                        if(!wizardp(me) && random(10) > 2) {
                                message_vision("$N趁没人注意的时候，鬼鬼祟祟地拿了点什么，放进怀里！\n", me);
                                me->set_temp("llx_marks/偷书", 1); 
                        }
                }
        }
        return 0;
}

int do_qiurao()
{
        int i;
        object *inv, me;
        me = this_player();
        message_vision(YEL"$N诚惶诚恐的跪在地上，痛苦流涕的说道: 我是笨蛋，我是傻瓜!我是笨蛋，我是傻瓜!\n\n" + "英俊潇洒，高大威猛的保镖统领们！饶了我吧，我再也不敢了!\n\n"NOR,me);
        message_vision(BLU "一个声音阴森森的说道，好吧，你走吧，但是要把你所有的东西留下！\n\n" NOR, me);
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                destruct(inv[i]);
                message("vision", RED "一阵清风卷过" + me->name() + "的全身，你发现身上什么都没有了。\n" NOR, environment(me));
                me->set_temp("llx_marks/偷书", 0); 
                }
        return 0;
}

int valid_leave(object me,string dir)
{
        object obj, man1, man2, man3;
        obj = this_object();
                
        if(dir == "up" && !wizardp(me))
        {
        message_vision(RED"有一层无形的屏障将$N挡住了，
        一个金属般的声音说道：你不属于那里，不能上去！\n"NOR,me);
        return notify_fail("");
        }
        if( userp(me) && me->query_temp("llx_marks/偷书"))
        {
                message_vision("你似乎想这样就走。\n", me);
                man1 = present("wguard", obj);
                man2 = present("gguard", obj);
                man3 = present("rguard", obj);
                if (!objectp(man1)) {
         message_vision(BLU"一条黑影从你头上一闪而下，压迫的你几乎喘不过来气……\n"NOR, me);
         man1 = new(__DIR__"npc/npc");
         man1->move(obj);
                        if (!objectp(man2)) {
         message_vision(BLU"一条黑影从你头上一闪而下，压迫的你几乎喘不过来气……\n"NOR, me);
         man1 = new(__DIR__"npc/npc1");
         man1->move(obj);
                                if (!objectp(man3)) {
         message_vision(BLU"一条黑影从你头上一闪而下，压迫的你几乎喘不过来气……\n"NOR, me);
         man1 = new(__DIR__"npc/npc2");
         man1->move(obj);
                message_vision(HIR"你第一次感觉到死亡离你这么近……\n"NOR,me);
        	me->set_temp("llx_marks/偷书",0);
		return notify_fail("");
                        }
                        }
                }
                
        }
        return 1;
}
