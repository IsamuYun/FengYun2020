inherit ROOM;
void create ()
{
  set ("short", "探花诗台");
  set ("long", @LONG
风云中的老老少少大都有吟诗对词的雅好。只要稍有灵感，就会带着笔墨到这里来
酝酿，等到灵光乍现那霎那，奋笔急书，以求千古名句。诗台正中朱笔入木狂草：
[33m
                       今日有酒今朝醉，
                       哪管它日剑割头！
                                       阿铁狂舞于酒后失意时。

[37m
LONG);

        set("jianyu_room",1);
  set("no_death_penalty", 1);
  set("objects", ([ /* sizeof() == 3 */
    __DIR__"npc/referee" : 1,
  __DIR__"npc/prince" : 1,
  __DIR__"npc/yaren" : 1,
"/d/wiz/fyup/npc/xiaoqiang" :1,
]));
  set("coor", ([ /* sizeof() == 3 */
  "y" : 1,
  "z" : 0,
  "x" : -10,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wcloud1",
  "up" : __DIR__"wenroom",
]));
        call_other( "/obj/board/fyyh_b", "???" );
  setup();
//  replace_program(ROOM);
}
void init()
{
        add_action("do_work", "2002");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(me->is_busy()) return notify_fail("你需要休息一会。\n");
if(me->query("2002")== 1) return notify_fail("你已经来奖励了，不能再奖励了。\n");
message_vision("希望$N在新的一年继续支持我们!\n",me);
ob = new("/questobj/obj/2002hongbao");
ob->move(me);
me->start_busy(1);
me->set("2002",1);
return 1;
}

